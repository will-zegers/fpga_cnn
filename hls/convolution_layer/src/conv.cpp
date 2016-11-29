#include <stdio.h>
#include "conv.h"

void convolution_node(
		X_TYPE channels[CHANNEL_COUNT][X_SIZE],
		W_TYPE filters[CHANNEL_COUNT][W_SIZE],
		Y_TYPE Y[Y_SIZE]) {

	int i;

	for (i = 0; i < Y_SIZE; ++i) {
		Y[i] = 0;
	}

	for (i = 0; i < CHANNEL_COUNT; ++i) {
		convolve(channels[i], filters[i], Y);
	}
}

void convolve(X_TYPE X[X_SIZE], W_TYPE weights[W_SIZE], Y_TYPE Y[Y_SIZE]) {

	X_TYPE subX[W_SIZE];

	int i,j,k;
	int q,r,s,t;

	t = 0;
	for (k = 0; k <= X_DMNIN - W_DMNIN; k += STRIDE) {
		for (q = 0; q <= X_DMNIN - W_DMNIN; q += STRIDE) {
			s = 0;
			for (i = k; i < k+W_DMNIN; ++i) {
				for (r = q; r < q+W_DMNIN; ++r) {
					Y[t] += X[X_DMNIN*i+r] * weights[s];
					s++;
				}
			}
			t++;
		}
	}
}
