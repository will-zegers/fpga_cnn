#include "conv_net.h"
#include <stdint.h>

void convolution_c1 (
			  DTYPE   X[C1_N_CHAN][C1_X_DMNIN][C1_X_DMNIN],
		const DTYPE   W[C1_N_CHAN][C1_N_FILTERS][C1_W_DMNIN][C1_W_DMNIN],
			  DTYPE out[C1_N_FILTERS][C1_OUT_DMNIN][C1_OUT_DMNIN],
		const DTYPE bias[C1_N_FILTERS]) {

	uint8_t ch, f, i, j, r, c;

	for (f = 0; f < C1_N_FILTERS; ++f) {
		for (r = 0; r < C1_OUT_DMNIN; ++r) {
			for (c = 0; c < C1_OUT_DMNIN; ++c) {
				out[f][r][c] = bias[f];
			}
		}

		for (ch = 0; ch < C1_N_CHAN; ++ch) {
			for (r = 0; r < C1_X_DMNIN - C1_W_DMNIN + 1; r += STRIDE) {
				for (c = 0, i = 0, j = 0; c < C1_X_DMNIN - C1_W_DMNIN + 1; c += STRIDE) {
					#pragma HLS PIPELINE
					for (i = 0; i < C1_W_DMNIN; ++i) {
						for (j = 0; j < C1_W_DMNIN; ++j) {
							out[f][r][c] += X[ch][r + i][j + c] * W[ch][f][i][j];
						}
					}
				}
			}
		}
	}
}

void convolution_c2 (
			  DTYPE   X[C2_N_CHAN][C2_X_DMNIN][C2_X_DMNIN],
		const DTYPE   W[C2_N_CHAN][C2_N_FILTERS][C2_W_DMNIN][C2_W_DMNIN],
			  DTYPE out[C2_N_FILTERS][C2_OUT_DMNIN][C2_OUT_DMNIN],
		const DTYPE bias[C2_N_FILTERS]) {

	uint8_t ch, f, i, j, r, c;

	for (f = 0; f < C2_N_FILTERS; ++f) {
		for (r = 0; r < C2_OUT_DMNIN; ++r) {
			for (c = 0; c < C2_OUT_DMNIN; ++c) {
				out[f][r][c] = bias[f];
			}
		}

		for (ch = 0; ch < C2_N_CHAN; ++ch) {
			for (r = 0; r < C2_X_DMNIN - C2_W_DMNIN + 1; r += STRIDE) {
				for (c = 0, i = 0, j = 0; c < C2_X_DMNIN - C2_W_DMNIN + 1; c += STRIDE) {
					#pragma HLS PIPELINE
					for (i = 0; i < C2_W_DMNIN; ++i) {
						for (j = 0; j < C2_W_DMNIN; ++j) {
							out[f][r][c] += X[ch][r + i][j + c] * W[ch][f][i][j];
						}
					}
				}
			}
		}
	}
}
