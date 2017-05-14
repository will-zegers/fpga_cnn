#include "conv.h"
#include <stdint.h>

void convolution_node(
		DTYPE channels[N_CHNLS][X_ROWS][X_COLS],
		DTYPE filters[N_CHNLS][W_ROWS][W_COLS],
		DTYPE Y[Y_ROWS][Y_COLS]) {

	uint8_t i, r, c;

	for (r = 0; r < Y_ROWS; ++r) {
		for (c = 0; c < Y_COLS; ++c) {
			Y[r][c] = 0;
		}
	}

	for (i = 0; i < N_CHNLS; ++i) {
		convolve(channels[i], filters[i], Y);
	}
}


void convolve(
		DTYPE X[X_ROWS][X_COLS],
		DTYPE W[W_ROWS][W_COLS],
		DTYPE Y[Y_ROWS][Y_COLS]) {

	uint8_t i, j, k, m;

	for (i = 0; i < X_ROWS - W_ROWS + 1; i += STRIDE) {
		for (j = 0, k = 0, m = 0; j < X_COLS - W_COLS + 1; j += STRIDE) {
		#pragma HLS PIPELINE
			for (k = 0; k < W_ROWS; k += 1) {
				for (m = 0; m < W_COLS; m += 1) {
					Y[i][j] += X[i + k][m + j] * W[k][m];
				}
			}
		}
	}
}
