#ifndef SOFTMAX_H
#define SOFTMAX_H

#include <stdint.h>

typedef float DTYPE;

const uint8_t SFMX_SIZE = 10;
const uint16_t RESOLUTION = 4000;

void softmax(DTYPE Z[SFMX_SIZE], DTYPE P[SFMX_SIZE]);
#endif
