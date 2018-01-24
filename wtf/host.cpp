#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include <thread>

#define N 16

struct packet {
    uint32_t v1;
};



void writer(int fdw) {
    struct packet *tologic;
    int i, rc, donebytes;
    float a, da;
    char *buf;

    tologic = (struct packet *)malloc(sizeof(struct packet) * (N + 3));
    if (!tologic) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    tologic[0].v1 = 4;
    tologic[1].v1 = 4;
    tologic[2].v1 = 4;
    for (i=3; i<N+3; i++) {
        tologic[i].v1 = 1;
    }

    buf = (char *) tologic;
    donebytes = 0;

    while (donebytes < sizeof(struct packet) * (N+3)) {
        rc = write(fdw, buf + donebytes, sizeof(struct packet) * (N+3) - donebytes);

        if ((rc < 0) && (errno == EINTR))
            continue;

        if (rc <= 0) {
            perror("write() failed");
            exit(1);
        }

        donebytes += rc;
    }

    for (i=0; i<N; i++) {
        tologic[i].v1 = i;
    }

    buf = (char *) tologic;
    donebytes = 0;

    while (donebytes < sizeof(struct packet) * N) {
        rc = write(fdw, buf + donebytes, sizeof(struct packet) * N - donebytes);

        if ((rc < 0) && (errno == EINTR))
            continue;

        if (rc <= 0) {
            perror("write() failed");
            exit(1);
        }

        donebytes += rc;
    }
    sleep(1); // Let debug output drain (if used)

    close(fdw);
}

void reader(int fdr) {
    struct packet *fromlogic;
    int i, rc, donebytes;
    float a, da;
    char *buf;

    fromlogic = (struct packet *)malloc(sizeof(struct packet) * N);
    if (!fromlogic) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    buf = (char *) fromlogic;
    donebytes = 0;

    while (donebytes < sizeof(struct packet) * N) {
        rc = read(fdr, buf + donebytes, sizeof(struct packet) * N - donebytes);

        if ((rc < 0) && (errno == EINTR))
            continue;

        if (rc < 0) {
            perror("read() failed");
            exit(1);
        }

        if (rc == 0) {
            fprintf(stderr, "Reached read EOF!? Should never happen.\n");
            exit(0);
        }

        donebytes += rc;
    }


    for (i=0; i<N; i++) {
        printf("%d\n", fromlogic[i].v1);
    }

    sleep(1); // Let debug output drain (if used)

    close(fdr);
}

int main(int argc, char *argv[]) {
    int fdr, fdw;

    fdr = open("/dev/xillybus_read_32", O_RDONLY);
    fdw = open("/dev/xillybus_write_32", O_WRONLY);

    if ((fdr < 0) || (fdw < 0)) {
        perror("Failed to open Xillybus device file(s)");
        exit(1);
    }

    std::thread write_thread(writer, fdw);
    std::thread read_thread(reader, fdr);

    write_thread.join();
    read_thread.join();

    printf("Main exiting\n");
    return 0;
}
