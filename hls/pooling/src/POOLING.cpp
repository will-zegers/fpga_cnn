#include "POOLING.h"
#include <stdint.h>

#define max(a,b) \
({ __typeof__ (a) _a = (a); \
   __typeof__ (b) _b = (b); \
 _a > _b ? _a : _b; })

DTYPE maxFour(DTYPE a, DTYPE b, DTYPE c, DTYPE d) {
	return max(max(a,b), max(c,d));
}

void POOLING(DTYPE in[SIZE][SIZE], DTYPE out[DOWNSIZE][DOWNSIZE]) {

	uint8_t i, j;

	for (i = 0; i < DOWNSIZE; i++) {
		for (j = 0; j < DOWNSIZE; j++) {
			out[i][j] = maxFour(
					in[i * S][j * S],
					in[i * S + 1][j * S],
					in[i * S][j * S + 1],
					in[i * S + 1][j * S + 1]
			);
		}
	}
}
