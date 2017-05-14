#include "linear.h"
#include <stdint.h>

void vec_mat_mul(
	DTYPE X[X_SIZE],
	DTYPE W[W_ROWS][W_COLS],
	DTYPE Z[Z_SIZE]) {

	uint8_t c;
	uint16_t r;

	for (c = 0; c < W_COLS; ++c) {
		Z[c] = 0;
		for (r = 0; r < X_SIZE; ++r) {
#pragma HLS PIPELINE
			Z[c] += X[r] * W[r][c];
		}
	}
}
