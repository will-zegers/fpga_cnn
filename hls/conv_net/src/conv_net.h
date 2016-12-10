#ifndef CONV_NET_H
#define CONV_NET_H

#define NORMALIZED 1

#include <stdint.h>

typedef float DTYPE;

const DTYPE MEAN = 25.509416422526;
const DTYPE STDV = 70.180423838273;

const uint8_t IMG_DMNIN = 32;
const uint8_t IMG_CHANNELS = 1;
const uint8_t STRIDE = 1;

const uint8_t C1_N_CHAN = 1;
const uint8_t C1_X_DMNIN = 32;
const uint8_t C1_W_DMNIN = 5;
const uint8_t C1_OUT_DMNIN = 28;
const uint8_t C1_N_FILTERS = 6;

const uint16_t A1_ROWS = 28;
const uint8_t A1_COLS = 28;

const uint8_t P1_SIZE = 28;
const uint8_t P1_DOWNSIZE = 14;

const uint8_t C2_N_CHAN = 6;
const uint8_t C2_X_DMNIN = 14;
const uint8_t C2_W_DMNIN = 5;
const uint8_t C2_OUT_DMNIN = 10;
const uint8_t C2_N_FILTERS = 16;

const uint16_t A2_ROWS = 10;
const uint8_t A2_COLS = 10;

const uint8_t P2_SIZE = 10;
const uint8_t P2_DOWNSIZE = 5;

const uint16_t FLAT_VEC_SZ = 400;

const uint8_t F1_ROWS = 120;
const uint16_t F1_COLS = 400;

const uint8_t F2_ROWS = 84;
const uint8_t F2_COLS = 120;

const uint8_t F3_ROWS = 10;
const uint8_t F3_COLS = 84;

const uint8_t SFMX_SIZE = 10;
const uint16_t SFMX_RES = 400;

void xillybus_wrapper(float *in, float *out);

DTYPE maxFour(DTYPE a, DTYPE b, DTYPE c, DTYPE d);

void predict(DTYPE img[IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN], DTYPE p[SFMX_SIZE]);

void normalize(
	DTYPE raw[IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN],
	DTYPE nml[IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN]);

void convolution_c1 (
			  DTYPE    X[C1_N_CHAN][C1_X_DMNIN][C1_X_DMNIN],
		const DTYPE    W[C1_N_CHAN][C1_N_FILTERS][C1_W_DMNIN][C1_W_DMNIN],
			  DTYPE  out[C1_N_FILTERS][C1_OUT_DMNIN][C1_OUT_DMNIN],
		const DTYPE bias[C1_N_FILTERS]);

void relu_a1(
		DTYPE in[C1_N_FILTERS][A1_ROWS][A1_COLS],
		DTYPE out[C1_N_FILTERS][A1_ROWS][A1_COLS]);

void pooling_p1(DTYPE in[C1_N_FILTERS][P1_SIZE][P1_SIZE],
		DTYPE out[C1_N_FILTERS][P1_DOWNSIZE][P1_DOWNSIZE]);

void convolution_c2 (
			  DTYPE    X[C2_N_CHAN][C2_X_DMNIN][C2_X_DMNIN],
		const DTYPE    W[C2_N_CHAN][C2_N_FILTERS][C2_W_DMNIN][C2_W_DMNIN],
			  DTYPE  out[C2_N_FILTERS][C2_OUT_DMNIN][C2_OUT_DMNIN],
		const DTYPE bias[C2_N_FILTERS]);

void relu_a2(
		DTYPE in[C2_N_FILTERS][A2_ROWS][A2_COLS],
		DTYPE out[C2_N_FILTERS][A2_ROWS][A2_COLS]);

void pooling_p2(
		DTYPE in[C2_N_FILTERS][P2_SIZE][P2_SIZE],
		DTYPE out[C2_N_FILTERS][P2_DOWNSIZE][P2_DOWNSIZE]);

void flatten(
		DTYPE IN[C2_N_FILTERS][P2_DOWNSIZE][P2_DOWNSIZE],
		DTYPE OUT[FLAT_VEC_SZ]);

void vec_mat_mul_f1(
			  DTYPE X[FLAT_VEC_SZ],
		const DTYPE W[F1_ROWS][F1_COLS],
		const DTYPE bias[F1_ROWS],
			  DTYPE Z[F1_ROWS]);

void relu_a3(DTYPE in[F1_ROWS], DTYPE out[F1_ROWS]);

void vec_mat_mul_f2(
	      DTYPE X[F1_ROWS],
	const DTYPE W[F2_ROWS][F2_COLS],
	const DTYPE bias[F2_ROWS],
	      DTYPE Z[F2_ROWS]);

void relu_a4(DTYPE in[F2_ROWS], DTYPE out[F2_ROWS]);

void vec_mat_mul_f3(
	      DTYPE X[F2_ROWS],
	const DTYPE W[F3_ROWS][F3_COLS],
	const DTYPE bias[F3_ROWS],
	      DTYPE Z[F3_ROWS]);

void softmax(DTYPE Z[SFMX_SIZE], DTYPE P[SFMX_SIZE]);

#endif
