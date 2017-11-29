#include <math.h>
#include <stdint.h>
#include "xilly_debug.h"

extern float sinf(float);

int mycalc(int a, float *x2) {
  *x2 = sinf(*x2);
  return a + 1;
}

void matrixMultiply(float* A, float* B, float* C)
{
 // matrix multiplication of a A*B matrix
	L1:for (int row = 0; row < 4; row++)
	{
		L2:for (int col = 0; col < 3; col++)
		{
			float sum = 0;
			L3:for (int z = 0; z < 2; z++)
			{
				sum += A[row * 2 + z] * B[z*3 + col];
			}
			C[row * 4 + col] = sum;
		}
	}
}

void xillybus_wrapper(float *in, float *out) {
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

  uint32_t x1, tmp, y1;
  float x2, y2;

  float A[8];
  float B[6];
  float C[12];

  xilly_puts("Let's Matrix Multiply\n");

	for (int i = 0; i < 8; i++)
	{
		A[i] = *in++;
	}

	for (int j = 0; j < 6; j++)
    {
		B[j] = *in++;
    }

  // Handle input data
  //x1 = *in++;
  //tmp = *in++;

  // Debug output
  //xilly_puts("x1=");
  //xilly_decprint(x1, 1);
  //xilly_puts("\n");

  matrixMultiply(A, B, C);

  	for (int k = 0; k < 12; k++)
  	{
  		*out++ = C[k];
  	}

  *out++ = tmp;
}
