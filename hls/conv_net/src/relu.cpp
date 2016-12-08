#include "conv_net.h"
#include <stdint.h>

void relu_a1(DTYPE in[C1_N_FILTERS][A1_ROWS][A1_COLS], DTYPE out[C1_N_FILTERS][A1_ROWS][A1_COLS]) {

	uint16_t r;
	uint8_t c, m;

	for (m = 0; m < C1_N_FILTERS; ++m) {
		for (r = 0; r < A1_ROWS; ++r) {
			for (c = 0; c < A1_COLS; ++c) {
			#pragma HLS PIPELINE
				out[m][r][c] = (in[m][r][c] > 0) ? (in[m][r][c]) : 0;
			}
		}
	}
}

void relu_a2(DTYPE in[C2_N_FILTERS][A2_ROWS][A2_COLS], DTYPE out[C1_N_FILTERS][A2_ROWS][A2_COLS]) {

	uint16_t r;
	uint8_t c, m;

	for (m = 0; m < C2_N_FILTERS; ++m) {
		for (r = 0; r < A2_ROWS; ++r) {
			for (c = 0; c < A2_COLS; ++c) {
			#pragma HLS PIPELINE
				out[m][r][c] = (in[m][r][c] > 0) ? (in[m][r][c]) : 0;
			}
		}
	}
}

void relu_a3(DTYPE in[F1_ROWS], DTYPE out[F1_ROWS]) {

	uint8_t i;

	for (i = 0; i < F1_ROWS; ++i) {
	#pragma HLS PIPELINE
		out[i] = (in[i] > 0) ? (in[i]) : 0;
	}
}

void relu_a4(DTYPE in[F2_ROWS], DTYPE out[F2_ROWS]) {

	uint8_t i;

	for (i = 0; i < F2_ROWS; ++i) {
	#pragma HLS PIPELINE
		out[i] = (in[i] > 0) ? (in[i]) : 0;
	}
}
