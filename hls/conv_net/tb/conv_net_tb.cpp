#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "conv_net.h"

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

const int N_SAMPLES = 1;

int main()
{
	int r,c,s;
	float temp;
	DTYPE img[N_SAMPLES][IMG_CHANNELS][IMG_DMNIN][IMG_DMNIN], prediction[N_SAMPLES][10];
	DTYPE gold;
	FILE *fp;

	fp = fopen("input_10.dat", "r");
	for (s = 0; s < N_SAMPLES; ++s) {
		for(r=0; r < 32; r++) {
			for (c = 0; c < IMG_DMNIN; c++) {
				fscanf(fp, "%f\n", &temp);
				img[s][0][r][c] = (DTYPE)temp;
			}
		}
		predict(img[s], prediction[s]);
		for (r = 0; r < 10; ++r) {
			printf("%f\n", prediction[s][r]);
		}
	}
	fclose(fp);

	fp = fopen("out_10.gold.dat", "r");
	for (s = 0; s < N_SAMPLES; ++s) {
		for (r = 0; r < 10; ++r) {
		  fscanf(fp, "%f\n", &gold);
		  rmse.add_value(prediction[s][r] - gold);
		}
	}
	fclose(fp);

	// printing error results
	printf("----------------------------------------------\n");
	printf("   RMSE ");
	printf("%0.15f\n", rmse.error);
	printf("----------------------------------------------\n");

	if (rmse.error > 0.001) {
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
	return 0;
}
