#include "softmax.h"
#include "Z_pow_of_e.h"
#include <stdint.h>

void softmax(DTYPE Z[SFMX_SIZE], DTYPE P[SFMX_SIZE]) {

	uint8_t i;
	uint16_t idx[SFMX_SIZE];
	DTYPE denom = 0;

	for (i = 0; i < SFMX_SIZE; ++i) {
		idx[i] = (RESOLUTION>>1) + (int)Z[i] * 1000;
		denom += eToZ[idx[i]];
	}

	for (i = 0; i < SFMX_SIZE; ++i) {
		P[i] = eToZ[idx[i]] / denom;
	}
}
