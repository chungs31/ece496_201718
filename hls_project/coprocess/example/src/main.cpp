#include <math.h>
#include <stdint.h>
#include "xilly_debug.h"
#include "assert.h"
#include "ap_fixed.h"

typedef ap_fixed<16,3, AP_RND, AP_WRAP> din_t;


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
	dotProduct = 0x03,
	gemm = 0x04
};

//static din_t filter[131072];
//static din_t B[262144];

static din_t filter[65536];
static din_t b_data[131072];
static din_t c_output[65536];

static uint32_t filter_dim = 0;

void matrixMultiply(int *in, int *out)
{
	int dim1;
	int dim2;
	int dim3;

	dim1 = *in++;
	dim2 = *in++;
	dim3 = *in++;

	int tmp;
	float tmp_fl;
	uint32_t tmp_u;

	for (int i = 0; i < dim1*dim2; i++)
	{
		tmp = *in++;
		tmp_fl = *((float *) &tmp);
		filter[i] = tmp_fl;;
	}

	for (int j = 0; j < dim2*dim3; j++)
    {
		tmp = *in++;
		tmp_fl = *((float *) &tmp);
		b_data[j] = tmp_fl;
    }

	//din_t* A, din_t* B, din_t* C, int dim1, int dim2, int dim3
	// matrix multiplication of a A*B matrix
	L1:for (int row = 0; row < dim1; row++)
	{
		L2:for (int col = 0; col < dim3; col++)
		{
			#pragma HLS pipeline
			din_t sum = 0;
			L3:for (int z = 0; z < dim2; z++)
			{
				sum += filter[row * dim2 + z] * b_data[z*dim3 + col];
			}
			c_output[row * dim3 + col] = sum;
			//tmp_fl = sum.to_float();
			//tmp_u = *((uint32_t *) &tmp_fl);
			//*out++ = tmp_u;
		}
	}

  	for (int k = 0; k < dim1*dim3; k++)
  	{
  		tmp_fl = c_output[k].to_float();
  		tmp_u = *((uint32_t *) &tmp_fl);
  		*out++ = tmp_u;
  	}
}

/*
void mm_18_parallel_dot_product(din_t in_a[A_ROWS][A_COLS],
		din_t in_b[A_COLS][B_COLS],
		din_t out_c[A_ROWS][B_COLS])
{
	din_t sum_mult;

	// matrix multiplication of a A*B matrix
	a_row_loop: for (int i = 0; i < A_ROWS; i++) {
		b_col_loop: for (int j = 0; j < B_COLS; j++) {
			#pragma HLS pipeline
			sum_mult = 0;
			a_col_loop: for (int k = 0; k < A_COLS; k++) {
				sum_mult += in_a[i][k] * in_b[k][j];
			}
			out_c[i][j] = sum_mult;
		}
	}
}
*/

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

	for (int i = 0; i < filter_dim; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS unroll factor=3
		tmp = *in++;
		sum += filter[i].to_float() * (*((float *) &tmp));
	}

	tmp = *((uint32_t *) &sum);
	*out++ = tmp;

	return;
}

void set_filter(int *in, int *out)
{
	uint32_t tmp;
	float tmp_fl;


#ifdef DEBUG
	xilly_puts("Setting filter\n");
#endif


	// Get dimension
	filter_dim = *in++;

	for (int i = 0; i < filter_dim; i++) {
#pragma HLS PIPELINE II=1
#pragma HLS unroll factor=3
		tmp = *in++;
		tmp_fl = *((float *) &tmp);
		filter[i] = tmp_fl;
	}

	return;
}

void xillybus_wrapper(int *in, int *out) {
#pragma AP interface ap_fifo port=in
#pragma AP interface ap_fifo port=out
#pragma AP interface ap_ctrl_none port=return

  //uint32_t x1, tmp, y1;
  //float x2, y2;
  //int dim1, dim2, dim3;

  uint32_t opcode;
  opcode = *in++;

  if (opcode == setFilter) {
	  set_filter(in, out);
  }
  else if (opcode == dotProduct) {
	  dot(in, out);
  }
  else if (opcode == gemm) {
	  matrixMultiply(in, out);
  }
}
