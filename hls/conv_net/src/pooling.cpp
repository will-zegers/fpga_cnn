#include "conv_net.h"
#include <stdint.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })

DTYPE maxFour(DTYPE a, DTYPE b, DTYPE c, DTYPE d) {
	return max(max(a,b), max(c,d));
}

void pooling_p1(DTYPE in[C1_N_FILTERS][P1_SIZE][P1_SIZE], DTYPE out[C1_N_FILTERS][P1_DOWNSIZE][P1_DOWNSIZE]) {

	uint8_t i, j, m;

	for (m = 0; m < C1_N_FILTERS; ++m) {
		for (i = 0; i < P1_DOWNSIZE; i++) {
			for (j = 0; j < P1_DOWNSIZE; j++) {
				out[m][i][j] = maxFour(
						in[m][i << 1][j << 1],
						in[m][(i << 1) + 1][j << 1],
						in[m][i << 1][(j << 1) + 1],
						in[m][(i << 1) + 1][(j << 1) + 1]
				);
			}
		}
	}
}

void pooling_p2(DTYPE in[C2_N_FILTERS][P2_SIZE][P2_SIZE], DTYPE out[C2_N_FILTERS][P2_DOWNSIZE][P2_DOWNSIZE]) {

	uint8_t i, j, m;

	for (m = 0; m < C2_N_FILTERS; ++m) {
		for (i = 0; i < P2_DOWNSIZE; i++) {
			for (j = 0; j < P2_DOWNSIZE; j++) {
				out[m][i][j] = maxFour(
						in[m][i << 1][j << 1],
						in[m][(i << 1) + 1][j << 1],
						in[m][i << 1][(j << 1) + 1],
						in[m][(i << 1) + 1][(j << 1) + 1]
				);
			}
		}
	}
}
