#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "conv.h"

struct Rmse
{
	int num_sq;
	float sum_sq;
	float error;

	Rmse(){ num_sq = 0; sum_sq = 0; error = 0; }

	float add_value(Y_TYPE d_n)
	{
		num_sq++;
		sum_sq += (float)(d_n*d_n);
		error = sqrtf(sum_sq / num_sq);
		return error;
	}
};

Rmse rmse;

int main() {
	int success;
	const float ERROR_THRESHOLD = 1e-3;
	X_TYPE channels[CHANNEL_COUNT][X_SIZE];
	W_TYPE filters[CHANNEL_COUNT][W_SIZE];
	Y_TYPE out[Y_SIZE], gold;
	FILE *fp;

	fp = fopen("channel0.dat", "r");
	for (int i = 0; i < X_SIZE; ++i) {
		fscanf(fp, "%d\n", &channels[0][i]);
	}
	fclose(fp);
	fp = fopen("channel1.dat", "r");
	for (int i = 0; i < X_SIZE; ++i) {
		fscanf(fp, "%d\n", &channels[1][i]);
	}
	fclose(fp);
	fp = fopen("channel2.dat", "r");
	for (int i = 0; i < X_SIZE; ++i) {
		fscanf(fp, "%d\n", &channels[2][i]);
	}
	fclose(fp);

	fp = fopen("filter0.dat", "r");
	for (int i = 0; i < W_SIZE; ++i) {
		fscanf(fp, "%f\n", &filters[0][i]);
	}
	fclose(fp);
	fp = fopen("filter1.dat", "r");
	for (int i = 0; i < W_SIZE; ++i) {
		fscanf(fp, "%f\n", &filters[1][i]);
	}
	fclose(fp);
	fp = fopen("filter2.dat", "r");
	for (int i = 0; i < W_SIZE; ++i) {
		fscanf(fp, "%f\n", &filters[2][i]);
	}
	fclose(fp);

	convolution_node(channels, filters, out);

	printf("Comparing with golden output\n");
	fp = fopen("out.gold.dat", "r");
	for (int i=0; i < Y_SIZE; ++i) {
		fscanf(fp, "%f\n", &gold);
		rmse.add_value(out[i] - gold);
	}
	fclose(fp);

	printf("RMSE: %0.15f\n", rmse.error);
	success = !(rmse.error < ERROR_THRESHOLD);

	fprintf(stdout, "*******************************************\n");
	if (success == 0) {
		fprintf(stdout, "PASS: The output matches the golden output!\n");
	} else {
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
	}
	fprintf(stdout, "*******************************************\n");
	return success;
}
