#ifndef LINEAR_H
#define LINEAR_H

#include <stdint.h>

typedef float DTYPE;

const uint16_t X_SIZE = 400;
const uint16_t W_ROWS = 400;
const uint8_t W_COLS = 120;
const uint8_t Z_SIZE = W_COLS;

const uint16_t MAT_SIZE = W_ROWS * W_COLS;

void vec_mat_mul(
		DTYPE X[X_SIZE],
		DTYPE W[W_ROWS][W_COLS],
		DTYPE Z[Z_SIZE]);

#endif
