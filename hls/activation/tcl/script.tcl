############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project RELU
set_top RELU
add_files RELU/RELU.h
add_files RELU/RELU.cpp
add_files -tb RELU/RELU_test.cpp
add_files -tb RELU/input.dat
add_files -tb RELU/out.gold.dat
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./RELU/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
