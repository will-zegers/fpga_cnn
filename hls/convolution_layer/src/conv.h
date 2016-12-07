#ifndef CONV_H_
#define CONV_H_

const int STRIDE = 1;
const int N_CHNLS = 3;

const int X_ROWS = 32;
const int X_COLS = 32;
const int W_ROWS = 5;
const int W_COLS = 5;
const int Y_ROWS = 1 + (X_ROWS - W_ROWS)/STRIDE;
const int Y_COLS = 1 + (X_COLS - W_COLS)/STRIDE;

typedef float INPT_TYPE;
typedef float WGHT_TYPE;
typedef float OUTP_TYPE;

void convolve(
		INPT_TYPE X[X_ROWS][X_COLS],
		WGHT_TYPE W[W_ROWS][W_COLS],
		OUTP_TYPE Y[Y_ROWS][Y_COLS]);

void convolution_node(
		INPT_TYPE channels[N_CHNLS][X_ROWS][X_COLS],
		WGHT_TYPE filters[N_CHNLS][W_ROWS][W_COLS],
		OUTP_TYPE Y[Y_ROWS][Y_COLS]);

#endif
