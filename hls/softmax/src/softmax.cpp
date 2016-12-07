#include "softmax.h"
#include "Z_pow_of_e.h"

void softmax(INPT_TYPE Z[SFMX_SIZE], OUTP_TYPE P[SFMX_SIZE]) {

	int i, idx[SFMX_SIZE];
	INPT_TYPE denom = 0;

	for (i = 0; i < SFMX_SIZE; ++i) {
		idx[i] = (RESOLUTION>>1) + (int)Z[i] * 1000;
		denom += eToZ[idx[i]];
	}

	for (i = 0; i < SFMX_SIZE; ++i) {
		P[i] = eToZ[idx[i]] / denom;
	}
}
