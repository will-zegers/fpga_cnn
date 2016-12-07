############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project convolution_layer
set_top convolution_node
add_files convolution_layer/conv.cpp
add_files convolution_layer/conv.h
add_files -tb convolution_layer/channel0.dat
add_files -tb convolution_layer/channel1.dat
add_files -tb convolution_layer/channel2.dat
add_files -tb convolution_layer/conv_tb.cpp
add_files -tb convolution_layer/filter0.dat
add_files -tb convolution_layer/filter1.dat
add_files -tb convolution_layer/filter2.dat
add_files -tb convolution_layer/out.gold.dat
open_solution "baseline1"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./convolution_layer/baseline1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
