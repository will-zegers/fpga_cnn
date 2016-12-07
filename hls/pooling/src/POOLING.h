#ifndef POOLING_H
#define POOLING_H

#include <stdint.h>

typedef float DTYPE;

const uint8_t SIZE = 28;
const uint8_t F = 2;
const uint8_t S = 2;
const uint8_t DOWNSIZE = (SIZE - F)/S + 1;

void POOLING(DTYPE in[SIZE][SIZE], DTYPE out[DOWNSIZE][DOWNSIZE]);
DTYPE maxFour(DTYPE a, DTYPE b, DTYPE c, DTYPE d);
#endif
