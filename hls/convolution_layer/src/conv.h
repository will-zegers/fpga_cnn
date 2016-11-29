#ifndef CONV_H_
#define CONV_H_

#include <stdint.h>

#define STRIDE 1
#define CHANNEL_COUNT 3

#define X_DMNIN 8
#define W_DMNIN 3
#define Y_DMNIN ((X_DMNIN-W_DMNIN)/STRIDE+1)

#define X_SIZE X_DMNIN*X_DMNIN
#define W_SIZE W_DMNIN*W_DMNIN
#define Y_SIZE Y_DMNIN*Y_DMNIN

typedef int X_TYPE;
typedef float W_TYPE;
typedef float Y_TYPE;

void convolve(X_TYPE X[X_SIZE], W_TYPE weights[W_SIZE], Y_TYPE Y[Y_SIZE]);
void convolution_node(
		X_TYPE channels[CHANNEL_COUNT][X_SIZE],
		W_TYPE filters[CHANNEL_COUNT][W_SIZE],
		Y_TYPE Y[Y_SIZE]);

#endif
