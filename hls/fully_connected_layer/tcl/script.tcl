############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project proj_matrix_multiply
set_top matrix_multiply_top
add_files matrix_multiply.cpp
add_files -tb weights.dat
add_files -tb out.gold.dat
add_files -tb matrix_multiply_tb.cpp
add_files -tb input.dat
add_files -tb golden.out.dat
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 7 -name default
#source "./proj_matrix_multiply/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
