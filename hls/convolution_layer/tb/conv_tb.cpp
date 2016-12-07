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

	float add_value(DTYPE d_n)
	{
		num_sq++;
		sum_sq += (float)(d_n*d_n);
		error = sqrtf(sum_sq / num_sq);
		return error;
	}
};

Rmse rmse;

int main() {
	int r, c;
	int success;
	const float ERROR_THRESHOLD = 1e-3;
	DTYPE channels[N_CHNLS][X_ROWS][X_COLS];
	DTYPE filters[N_CHNLS][W_ROWS][W_COLS];
	DTYPE out[Y_ROWS][Y_COLS], gold;
	FILE *fp;

	fp = fopen("channel0.dat", "r");
	for (r = 0; r < X_ROWS; ++r) {
		for (c = 0; c < X_COLS; ++c) {
			fscanf(fp, "%f\n", &channels[0][r][c]);
		}
	}
	fclose(fp);

	fp = fopen("channel1.dat", "r");
	for (r = 0; r < X_ROWS; ++r) {
		for (c = 0; c < X_COLS; ++c) {
			fscanf(fp, "%f\n", &channels[1][r][c]);
		}
	}
	fclose(fp);

	fp = fopen("channel2.dat", "r");
	for (r = 0; r < X_ROWS; ++r) {
		for (c = 0; c < X_COLS; ++c) {
			fscanf(fp, "%f\n", &channels[2][r][c]);
		}
	}
	fclose(fp);

	fp = fopen("filter0.dat", "r");
	for (r = 0; r < W_ROWS; ++r) {
		for (c = 0; c < W_COLS; ++c) {
			fscanf(fp, "%f\n", &filters[0][r][c]);
		}
	}
	fclose(fp);

	fp = fopen("filter1.dat", "r");
	for (r = 0; r < W_ROWS; ++r) {
		for (c = 0; c < W_COLS; ++c) {
			fscanf(fp, "%f\n", &filters[1][r][c]);
		}
	}
	fclose(fp);

	fp = fopen("filter2.dat", "r");
	for (r = 0; r < W_ROWS; ++r) {
		for (c = 0; c < W_COLS; ++c) {
			fscanf(fp, "%f\n", &filters[2][r][c]);
		}
	}
	fclose(fp);

	convolution_node(channels, filters, out);

	printf("Comparing with golden output\n");
	fp = fopen("out.gold.dat", "r");
	for (r = 0; r < Y_ROWS; ++r) {
		for (c = 0; c < Y_COLS; ++c) {
			fscanf(fp, "%f\n", &gold);
			printf("%f %f\n", out[r][c], gold);
			rmse.add_value(out[r][c] - gold);
		}
	}
	fclose(fp);


	// printing error results
	printf("----------------------------------------------\n");
	printf("   RMSE(R)");
	printf("%0.15f\n", rmse.error);
	printf("----------------------------------------------\n");

	if (rmse.error > 0.1) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
	    return 1;
	}else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
	    return 0;
	}
}
