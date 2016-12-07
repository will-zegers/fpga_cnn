#include "linear.h"
#include <stdio.h>

void vec_mat_mul(
	INPT_TYPE X[X_SIZE],
	WGHT_TYPE W[W_ROWS][W_COLS],
	OUTP_TYPE Z[Z_SIZE]) {

	int i, r, c;

	for (c = 0; c < W_COLS; ++c) {
		Z[c] = 0;
		for (r = 0; r < X_SIZE; ++r) {
#pragma HLS PIPELINE
			Z[c] += X[r] * W[r][c];
		}
	}
}
