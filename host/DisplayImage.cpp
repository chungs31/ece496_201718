#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

#include <opencv2/opencv.hpp>
#include <time.h> 

using namespace cv;

struct packet {
  uint32_t v1;
  float v2;
};

int main(int argc, char *argv[]) {
  int fdr, fdw, rc, donebytes;
  char *buf;
  pid_t pid;
  struct packet *tologic, *fromlogic;
  int i;
  float a, da;

  if (argc != 2) {
    printf("usage: DisplayImage.out <Image_Path>\n");
    return -1;
  }

  Mat image; 
  image = imread(argv[1], 1);
  Mat t_image = image.clone();

  if (!image.data) {
    printf("No image data\n");
    return -1;
  }



  int channels = image.channels();

  int nRows = image.rows;
  int nCols = image.cols * channels;
  int image_flattened_length = nRows * nCols;

  std::cout << "Image = " << std::endl << " " << image.cols << "," << image.rows << "," << image.channels()  <<"," 
         << image.isContinuous() << std::endl << std::endl;

  std::cout << "Matrix type: " << image.type() << std::endl;
  CV_Assert(image.depth() == CV_8U); // only accept char type matrices

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

    //tologic = (struct packet *)malloc(sizeof(struct packet) * N);
    tologic = new packet[image_flattened_length];
    if (!tologic) {
      fprintf(stderr, "Failed to allocate memory\n");
      exit(1);
    }

    // Fill array of structures with just some numbers
    uchar *p;    
    int temp = 0;
    for( i = 0; i < nRows; ++i)
    {
        p = image.ptr<uchar>(i);
        for (int j = 0; j < nCols; ++j)
        {
            tologic[temp].v1 = (uint32_t) p[j];
            tologic[temp++].v2 = i;
        }
    }
    printf("temp index %d\n", temp);

    buf = (char *) tologic;
    donebytes = 0;

    while (donebytes < sizeof(struct packet) * image_flattened_length) {
      rc = write(fdw, buf + donebytes, sizeof(struct packet) * image_flattened_length - donebytes);

      if ((rc < 0) && (errno == EINTR))
	continue;

      if (rc <= 0) {
	perror("write() failed");
	exit(1);
      }

      donebytes += rc;
    }
    printf("donebytes %u\n", donebytes);

    sleep(1); // Let debug output drain (if used)

    close(fdw);
    return 0;
  } else {
    close(fdw);

    int flags = fcntl(fdr, F_GETFL, 0);
    fcntl(fdr, F_SETFL, flags | O_NONBLOCK);

    fromlogic = (struct packet *)malloc(sizeof(struct packet) * image_flattened_length);
    if (!fromlogic) {
      fprintf(stderr, "Failed to allocate memory\n");
      exit(1);
    }

    buf = (char *) fromlogic;
    donebytes = 0;
    image_flattened_length;

    time_t begin = time(NULL); 
    while (donebytes < sizeof(struct packet) * image_flattened_length) {
      rc = read(fdr, buf + donebytes, sizeof(struct packet) * image_flattened_length - donebytes);
      time_t now = time(NULL);

      if ((rc < 0) && (errno == EINTR || errno == EAGAIN))
	continue;

      if (rc < 0 || ((now-begin)>10)) {
	perror("read() failed");
	exit(1);
      }

      if (rc == 0) {
	fprintf(stderr, "Reached read EOF!? Should never happen.\n");
	exit(0);
      }

      donebytes += rc;
    }

    uchar *p;    
    int temp = 0;
    for( i = 0; i < nRows; ++i)
    {
        p = t_image.ptr<uchar>(i);
        for (int j = 0; j < nCols; ++j, temp++)
        {
            p[j] = fromlogic[temp].v1 + 20;
        }
    }
   
    namedWindow("Transformed Image", WINDOW_AUTOSIZE);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Transformed Image", t_image);
    imshow("Display Image", image);
    waitKey(0);

    sleep(1); // Let debug output drain (if used)

    close(fdr);
    return 0;
  }
}
