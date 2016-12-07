#ifndef LINEAR_H
#define LINEAR_H

typedef float INPT_TYPE;
typedef float WGHT_TYPE;
typedef WGHT_TYPE OUTP_TYPE;

const int X_SIZE = 400;
const int W_ROWS = 400;
const int W_COLS = 120;
const int Z_SIZE = W_COLS;
const int MAT_SIZE = W_ROWS * W_COLS;

void vec_mat_mul(
		INPT_TYPE X[X_SIZE],
		WGHT_TYPE W[W_ROWS][W_COLS],
		OUTP_TYPE Z[Z_SIZE]);

#endif
