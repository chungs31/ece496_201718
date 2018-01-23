#include <math.h>
#include <stdint.h>
#include "xilly_debug.h"

extern float sinf(float);

int mycalc(int a, float *x2) {
  *x2 = sinf(*x2);
  return a + 1;
}

void matrixMultiply(float* A, float* B, float* C, int dim1, int dim2, int dim3)
{
 // matrix multiplication of a A*B matrix
	L1:for (int row = 0; row < dim1; row++)
	{
		L2:for (int col = 0; col < dim3; col++)
		{
			float sum = 0;
			L3:for (int z = 0; z < dim2; z++)
			{
				sum += A[row * dim2 + z] * B[z*dim3 + col];
			}
			C[row * dim3 + col] = sum;
		}
	}
}

void xillybus_wrapper(float *in, float *out) {
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

  uint32_t x1, tmp, y1;
  float x2, y2;

  int dim1;
  int dim2;
  int dim3;

  dim1 = *in++;
  dim2 = *in++;
  dim3 = *in++;

  float A[10240];
  float B[10240];
  float C[10240];

  xilly_puts("Let's Matrix Multiply\n");

	for (int i = 0; i < dim1*dim2; i++)
	{
		A[i] = *in++;
	}

	for (int j = 0; j < dim2*dim3; j++)
    {
		B[j] = *in++;
    }

  matrixMultiply(A, B, C, dim1, dim2, dim3);

  	for (int k = 0; k < dim1*dim3; k++)
  	{
  		xilly_puts("C is");
  		xilly_decprint(C[k], 2);
  		xilly_puts("\n");

  		*out++ = C[k];
  	}

  *out++ = tmp;
}
