/*****************************************************************************
 *
 *     Author: Xilinx, Inc.
 *
 *     This text contains proprietary, confidential information of
 *     Xilinx, Inc. , is distributed by under license from Xilinx,
 *     Inc., and may be used, copied and/or disclosed only pursuant to
 *     the terms of a valid license agreement with Xilinx, Inc.
 *
 *     XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS"
 *     AS A COURTESY TO YOU, SOLELY FOR USE IN DEVELOPING PROGRAMS AND
 *     SOLUTIONS FOR XILINX DEVICES.  BY PROVIDING THIS DESIGN, CODE,
 *     OR INFORMATION AS ONE POSSIBLE IMPLEMENTATION OF THIS FEATURE,
 *     APPLICATION OR STANDARD, XILINX IS MAKING NO REPRESENTATION
 *     THAT THIS IMPLEMENTATION IS FREE FROM ANY CLAIMS OF INFRINGEMENT,
 *     AND YOU ARE RESPONSIBLE FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE
 *     FOR YOUR IMPLEMENTATION.  XILINX EXPRESSLY DISCLAIMS ANY
 *     WARRANTY WHATSOEVER WITH RESPECT TO THE ADEQUACY OF THE
 *     IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO ANY WARRANTIES OR
 *     REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE FROM CLAIMS OF
 *     INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *     FOR A PARTICULAR PURPOSE.
 *
 *     Xilinx products are not intended for use in life support appliances,
 *     devices, or systems. Use in such applications is expressly prohibited.
 *
 *     (c) Copyright 2013-2014 Xilinx Inc.
 *     All rights reserved.
 *
 *****************************************************************************/

#include "stdio.h"
#include "matrix_multiply.h"
#include "hls/linear_algebra/utils/x_hls_matrix_utils.h"
#include "hls/linear_algebra/utils/x_hls_matrix_tb_utils.h"

struct Rmse
{
	int num_sq;
	float sum_sq;
	float error;

	Rmse(){ num_sq = 0; sum_sq = 0; error = 0; }

	float add_value(float d_n)
	{
		num_sq++;
		sum_sq += (float)(d_n*d_n);
		error = sqrtf(sum_sq / num_sq);
		return error;
	}
};

Rmse rmse;

int main (void){

  int r, c;
  float gold;
  FILE *fp;

  MATRIX_T X[X_ROWS][X_COLS];
  MATRIX_T W[W_ROWS][W_COLS];
  MATRIX_T Z[Z_ROWS][Z_COLS];

  fp = fopen("input.dat", "r");
  for (r = 0; r < X_ROWS; ++r) {
	  for (c = 0; c < X_COLS; ++c) {
		  fscanf(fp, "%f\n", &X[r][c]);
	  }
  }
  fclose(fp);

  fp = fopen("weights.dat", "r");
  for (r = 0; r < W_ROWS; ++r) {
	  for (c = 0; c < W_COLS; ++c) {
		  fscanf(fp, "%f\n", &W[r][c]);
	  }
  }
  fclose(fp);

  matrix_multiply_top(X, W, Z);

  fp = fopen("out.gold.dat", "r");
  for (r = 0; r < Z_ROWS; ++r) {
	  for (c = 0; c < Z_COLS; ++c) {
		  fscanf(fp, "%f\n", &gold);
		  rmse.add_value(Z[r][c] - gold);
	  }
  }
  fclose(fp);

	// printing error results
	printf("----------------------------------------------\n");
	printf("   RMSE ");
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
