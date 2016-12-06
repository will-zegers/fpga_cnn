#include "RELU.h"
#include <stdio.h>

void RELU(DTYPE in[nROWS][nCOLS], DTYPE out[nROWS][nCOLS]) {
	int r, c;

	for (r = 0; r < nROWS; ++r) {
		for (c = 0; c < nROWS; ++c) {
			out[r][c] = (in[r][c] > 0) ? (in[r][c]) : 0;
		}
	}
}
