from math import sqrt
import numpy as np
from cnn_util import params
from cnn_funcs import convolve

def convolution_layer(channels, filters, stride, pad, bias):

    i_rows = params['Input rows']
    i_cols = params['Input cols']
    w_rows = params['Weights rows']
    w_cols = params['Weights cols']

    zH = 1+ (i_cols - w_cols + 2*pad)/stride
    zW = 1 + (i_rows - w_rows + 2 * pad) / stride
    z = np.zeros(zW * zH)
    for channel,fil in zip(channels,filters):
        z += convolve(channel, fil, stride, pad)

    return np.add(z,np.array([bias] * (zW * zH)))