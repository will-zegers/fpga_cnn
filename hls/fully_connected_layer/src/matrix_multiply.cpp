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

#include "matrix_multiply.h"

// The top-level function to synthesize
//
void matrix_multiply_top(const MATRIX_T X [X_ROWS][X_COLS],
                    const MATRIX_T W [W_ROWS][W_COLS],
                    MATRIX_T Z[Z_ROWS][Z_COLS]){

  MATRIX_T x_i [X_ROWS][X_COLS];
  MATRIX_T w_i [W_ROWS][W_COLS];
  MATRIX_T z_i [Z_ROWS][Z_COLS];

  // Copy input data to local memory
  x_row_loop : for (int r = 0; r < X_ROWS; r++) {
    x_col_loop : for (int c = 0;c < X_COLS; c++) {
      x_i[r][c] = X[r][c];
    }
  }
  w_row_loop :  for (int r = 0;r < W_ROWS; r++) {
    w_col_loop : for (int c = 0;c < W_COLS; c++) {
      w_i[r][c] = W[r][c];
    }
  }

  // Call multiplier
  hls::matrix_multiply <hls::NoTranspose, hls::NoTranspose, X_ROWS, X_COLS, W_ROWS, W_COLS, Z_ROWS, Z_COLS, MATRIX_T, MATRIX_T> (x_i, w_i, z_i);

  // Copy local memory contents to outputs
  z_row_loop : for (int r = 0; r < Z_ROWS; r++) {
    z_col_loop : for (int c = 0; c < Z_COLS; c++) {
      Z[r][c] = z_i[r][c];
    }
  }
}
