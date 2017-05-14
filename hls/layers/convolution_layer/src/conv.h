#ifndef CONV_H_
#define CONV_H_

#include <stdint.h>

typedef float DTYPE;

const uint8_t STRIDE = 1;
const uint8_t N_CHNLS = 3;

const uint8_t X_ROWS = 32;
const uint8_t X_COLS = 32;
const uint8_t W_ROWS = 5;
const uint8_t W_COLS = 5;
const uint8_t Y_ROWS = 1 + (X_ROWS - W_ROWS)/STRIDE;
const uint8_t Y_COLS = 1 + (X_COLS - W_COLS)/STRIDE;

void convolve(
		DTYPE X[X_ROWS][X_COLS],
		DTYPE W[W_ROWS][W_COLS],
		DTYPE Y[Y_ROWS][Y_COLS]);

void convolution_node(
		DTYPE channels[N_CHNLS][X_ROWS][X_COLS],
		DTYPE filters[N_CHNLS][W_ROWS][W_COLS],
		DTYPE Y[Y_ROWS][Y_COLS]);

#endif
