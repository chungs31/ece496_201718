#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include <opencv2/opencv.hpp>

#define N 1000

using namespace cv;
Mat gemm_fpga(Mat A, Mat B);
void write_mat_to_xillybus(Mat I, int fdw);
Mat gemm_fpga(Mat A, Mat B);

int main(int argc, char *argv[]) {
    float d[4][2] = {{ 3, 2},
        {-6, 6},
        { 0, 1},
        {10,-7}};

    float b[2][3] = { { 7, 2,10},
        { 6,10,19} };

    Mat A = Mat(4,2 ,CV_32FC1, d);
    Mat B = Mat(2,3, CV_32FC1, b);

    Mat x_cpu = A * B;
    Mat x_fpga = gemm_fpga(A, B);

    std::cout << "x_cpu=" << std::endl << " " << x_cpu << std::endl;
    std::cout << "x_fpga=" << std::endl << " " << x_fpga << std::endl;

    return 0;
}

void write_mat_to_xillybus(Mat I, int fdw) {
    // accept only char type matrices
    CV_Assert(I.depth() == CV_32FC1);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    float* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<float>(i);
        for ( j = 0; j < nCols; ++j)
        {
            write(fdw, (void *) &p[j], sizeof(float));
        }
    } 
}

Mat read_mat_to_xillybus(int fdr) {
    Mat I = Mat::zeros(4,3, CV_32FC1);

    int channels = I.channels();

    int nRows = I.rows;
    int nCols = I.cols * channels;

    if (I.isContinuous())
    {
        nCols *= nRows;
        nRows = 1;
    }

    int i,j;
    float* p;
    for( i = 0; i < nRows; ++i)
    {
        p = I.ptr<float>(i);
        for ( j = 0; j < nCols; ++j)
        {
            read(fdr, (void *) &p[j], sizeof(float));
        }
    }

    return I; 
}

Mat gemm_fpga(Mat A, Mat B) {
    printf("Matrix A is %u bytes, Matrix B is %u bytes\n", sizeof(A), sizeof(B));

    int fdr, fdw;

    fdr = open("/dev/xillybus_read_32", O_RDONLY);
    fdw = open("/dev/xillybus_write_32", O_WRONLY);

    if ((fdr < 0) || (fdw < 0)) {
        perror("Failed to open Xillybus device file(s)");
        exit(1);
    }

    write_mat_to_xillybus(A, fdw);
    write_mat_to_xillybus(B, fdw);
    Mat ret = read_mat_to_xillybus(fdr);

    close(fdr);
    close(fdw);

    return ret;
}

/*
   Mat gemm_fpga(Mat A, Mat B) {
   int fdr, fdw, rc, donebytes;
   char *buf;
   pid_t pid;
   struct packet *tologic, *fromlogic;
   int i;
   float a, da;

   fdr = open("/dev/xillybus_read_32", O_RDONLY);
   fdw = open("/dev/xillybus_write_32", O_WRONLY);

   if ((fdr < 0) || (fdw < 0)) {
   perror("Failed to open Xillybus device file(s)");
   exit(1);
   }

   pid = fork();

   if (pid < 0) {
   perror("Failed to fork()");
   exit(1);
   }

   if (pid) {
   close(fdr);

   tologic = new packet[N];
   if (!tologic) {
   fprintf(stderr, "Failed to allocate memory\n");
   exit(1);
   }

// Fill array of structures with just some numbers
da = 6.283185 / ((float) N);

for (i=0, a=0.0; i<N; i++, a+=da) {
tologic[i].v1 = i;
tologic[i].v2 = a;
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
return 0;
} else {
close(fdw);

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

for (i=0; i<N; i++)
printf("%d: %f\n", fromlogic[i].v1, fromlogic[i].v2);

sleep(1); // Let debug output drain (if used)

close(fdr);
return 0;
}
}
*/

