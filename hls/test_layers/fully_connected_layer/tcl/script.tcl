############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project linear
set_top vec_mat_mul
add_files linear/linear.h
add_files linear/linear.cpp
add_files -tb linear/weights.dat
add_files -tb linear/out.gold.dat
add_files -tb linear/linear_tb.cpp
add_files -tb linear/input.dat
open_solution "baseline_pipeline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./linear/baseline_pipeline/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
