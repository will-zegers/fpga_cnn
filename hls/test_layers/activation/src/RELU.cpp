#include "RELU.h"
#include <stdint.h>

void RELU(DTYPE in[nROWS][nCOLS], DTYPE out[nROWS][nCOLS]) {

	uint16_t r;
	uint8_t c;

	for (r = 0; r < nROWS; ++r) {
		for (c = 0; c < nCOLS; ++c) {
#pragma HLS PIPELINE
			out[r][c] = (in[r][c] > 0) ? (in[r][c]) : 0;
		}
	}
}
