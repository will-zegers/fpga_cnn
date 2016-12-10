#include "conv_net.h"

void normalize(
	DTYPE raw[IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN],
	DTYPE nml[IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN]) {

	uint8_t c,l,r;

	for (l = 0; l < IMG_CHANNELS; ++l) {
		for (r = 0; r < IMG_DMNIN; ++r) {
			for (c = 0; c < IMG_DMNIN; ++c) {
				nml[l][r][c] = (raw[l][r][c] - MEAN) / STDV;
			}
		}
	}
}
