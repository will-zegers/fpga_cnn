#include "conv_net.h"

void flatten(
		DTYPE IN[C2_N_FILTERS][P2_DOWNSIZE][P2_DOWNSIZE],
		DTYPE OUT[FLAT_VEC_SZ]) {

	uint8_t i,j,k;
	uint16_t t;

	for (i = 0, t = 0; i < C2_N_FILTERS; ++i) {
		for (j = 0; j < P2_DOWNSIZE; ++j) {
			for (k = 0; k < P2_DOWNSIZE; ++k) {
				OUT[t] = IN[i][j][k];
				t += 1;
			}
		}
	}
}
