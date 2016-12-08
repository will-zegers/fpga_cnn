#include "conv_net.h"
#include "expZ.h"
#include <stdint.h>

void softmax(DTYPE Z[SFMX_SIZE], DTYPE P[SFMX_SIZE]) {

	uint8_t i;
	uint16_t idx[SFMX_SIZE];

	DTYPE denom = 0;
	for (i = 0; i < SFMX_SIZE; ++i) {
		idx[i] = (SFMX_RES>>1) + (int)(Z[i] * 10);
		denom += expZ[idx[i]];
	}

	for (i = 0; i < SFMX_SIZE; ++i) {
		P[i] = expZ[idx[i]] / denom;
	}
}
