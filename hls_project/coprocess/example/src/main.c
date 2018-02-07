#include <math.h>
#include <stdint.h>
#include "xilly_debug.h"
#include "assert.h"

#define DEBUG

/*
extern float sinf(float);

int mycalc(int a, float *x2) {
  *x2 = sinf(*x2);
  return a + 1;
}
*/

enum opcode {
	setFilter = 0x01,
	flushFilter = 0x02,
	dotProduct = 0x03
};

static float filter[16384];
static uint32_t filter_dim = 0;

void matrixMultiply(uint32_t* A, uint32_t* B, uint32_t* C, int dim1, int dim2, int dim3)
{
    // matrix multiplication of a A*B matrix
	L1:for (int row = 0; row < dim1; row++)
	{
		L2:for (int col = 0; col < dim3; col++)
		{
			uint32_t sum = 0;
			L3:for (int z = 0; z < dim2; z++)
			{
				sum += A[row * dim2 + z] * B[z*dim3 + col];
			}
			C[row * dim3 + col] = sum;
		}
	}
}

void dot(int *in, int *out)
{
	float sum = 0;
	uint32_t tmp;

#ifdef DEBUG
	xilly_puts("Doing dot product\n");
#endif

	// Get input vector
	// NOTE: it is expected that the incoming vector
	// has the same # of elements as the filter
	// Incorrectly set filters will cause problems!

	assert(filter_dim > 0);
	for (int i = 0; i < filter_dim; i++) {
#pragma HLS PIPELINE II=1
		tmp = *in++;
		sum += filter[i] * (*((float *) &tmp));
	}

	tmp = *((uint32_t *) &sum);
	*out++ = tmp;

	return;
}

void set_filter(int *in, int *out)
{
	uint32_t tmp;

#ifdef DEBUG
	xilly_puts("Setting filter\n");
#endif

	// Get dimension
	filter_dim = *in++;

	for (int i = 0; i < filter_dim; i++) {
#pragma HLS PIPELINE II=1
		tmp = *in++;
		filter[i] = *((float *) &tmp);
	}

	return;
}

void xillybus_wrapper(int *in, int *out) {
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

  uint32_t x1, tmp, y1;
  float x2, y2;



  //xilly_puts("op,");

  uint32_t opcode;
  opcode = *in++;

  if (opcode == setFilter) {
	  set_filter(in, out);
  }
  else if (opcode == dotProduct) {
	  dot(in, out);
  }


  // Handle input data
  /*
  x1 = *in++;
  tmp = *in++;
  x2 = *((float *) &tmp); // Convert uint32_t to float
  */

  /*
  uint32_t m, k, n;
  m = *in++;
  k = *in++;
  n = *in++;
  */


  /*
  xilly_puts("m/k/n ");
  xilly_decprint(m, 2);
  xilly_puts("/");
  xilly_decprint(k, 2);
  xilly_puts("/");
  xilly_decprint(n, 2);
  xilly_puts("\n");
  */

  /*
  for (int x = 0; x < m*k; x++) {
	  A[x] = *in++;
  }
  for (int y = 0; y < k*n; y++) {
	  B[y] = *in++;
  }
  */
  //xilly_puts("All received. Matrix Multiplying\n");
  /*
  matrixMultiply(A, B, C, m, k, n);

  for (int z = 0; z < m*n; z++) {
	  *out++ = C[z];
  }
  */

  //xilly_puts("Echo complete\n");

  // Debug output
  /*
  xilly_puts("x1=");
  xilly_decprint(x1, 1);
  xilly_puts("\n");
  */

  // Run the calculations
  /*
  y1 = mycalc(x1, &x2);
  y2 = x2; // This helps HLS in the conversion below
  */

  // Handle output data
  /*
  tmp = *((uint32_t *) &y2); // Convert float to uint32_t
  *out++ = y1;
  *out++ = tmp;
  */
}
