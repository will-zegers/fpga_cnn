#ifndef RELU_H
#define RELU_H

#include <stdint.h>

const uint16_t nROWS = 400;
const uint8_t nCOLS = 120;

typedef float DTYPE;

void RELU(DTYPE in[nROWS][nCOLS], DTYPE out[nROWS][nCOLS]);

#endif
