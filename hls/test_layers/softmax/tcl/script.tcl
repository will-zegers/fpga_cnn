############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project softmax_layer
set_top softmax
add_files softmax_layer/Z_pow_of_e.h
add_files softmax_layer/softmax.cpp
add_files softmax_layer/softmax.h
add_files -tb softmax_layer/input.dat
add_files -tb softmax_layer/out.gold.dat
add_files -tb softmax_layer/softmax_tb.cpp
open_solution "baseline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./softmax_layer/baseline/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
