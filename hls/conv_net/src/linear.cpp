#include "conv_net.h"
#include <stdint.h>

void vec_mat_mul_f1(
	      DTYPE X[FLAT_VEC_SZ],
	const DTYPE W[F1_ROWS][F1_COLS],
	const DTYPE bias[F1_ROWS],
	      DTYPE Z[F1_ROWS]) {

	uint16_t c;
	uint8_t r;

	for (r = 0; r < F1_ROWS; ++r) {
		Z[r] = bias[r];
		for (c = 0; c < F1_COLS; ++c) {
		#pragma HLS PIPELINE
			Z[r] += W[r][c] * X[c];
		}
	}
}

void vec_mat_mul_f2(
	      DTYPE X[F1_ROWS],
	const DTYPE W[F2_ROWS][F2_COLS],
	const DTYPE bias[F2_ROWS],
	      DTYPE Z[F2_ROWS]) {

	uint8_t r, c;

	for (r = 0; r < F2_ROWS; ++r) {
		Z[r] = bias[r];
		for (c = 0; c < F2_COLS; ++c) {
		#pragma HLS PIPELINE
			Z[r] += W[r][c] * X[c];
		}
	}
}

void vec_mat_mul_f3(
	      DTYPE X[F2_ROWS],
	const DTYPE W[F3_ROWS][F3_COLS],
	const DTYPE bias[F3_ROWS],
	      DTYPE Z[F3_ROWS]) {
#pragma HLS INLINE

	uint8_t r, c;

	for (r = 0; r < F3_ROWS; ++r) {
		Z[r] = bias[r];
		for (c = 0; c < F3_COLS; ++c) {
		#pragma HLS PIPELINE
			Z[r] += W[r][c] * X[c];
		}
	}
}
