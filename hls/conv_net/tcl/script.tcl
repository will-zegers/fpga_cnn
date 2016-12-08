############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project conv_net
set_top predict
add_files conv_net/biases.h
add_files conv_net/conv.cpp
add_files conv_net/conv_net.cpp
add_files conv_net/conv_net.h
add_files conv_net/expZ.h
add_files conv_net/flatten.cpp
add_files conv_net/linear.cpp
add_files conv_net/pooling.cpp
add_files conv_net/relu.cpp
add_files conv_net/softmax.cpp
add_files conv_net/weights.h
add_files -tb conv_net/conv_net_tb.cpp
add_files -tb conv_net/input_10.dat
add_files -tb conv_net/input_5.dat
add_files -tb conv_net/out_10.gold.dat
add_files -tb conv_net/out_5.gold.dat
open_solution "baseline"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
#source "./conv_net/baseline/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
