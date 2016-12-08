#ifndef LINEAR_H
#define LINEAR_H

#include <stdint.h>
#include "ap_fixed.h"

typedef float DTYPE;

void vec_mat_mul(
		DTYPE X[X_SIZE],
		DTYPE W[W_ROWS][W_COLS],
		DTYPE Z[Z_SIZE]);

#endif
