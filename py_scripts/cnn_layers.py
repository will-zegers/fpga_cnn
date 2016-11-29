from math import sqrt
import numpy as np
from cnn_funcs import convolve

def convolution_layer(channels, filters, stride, pad, bias):

    w = int(sqrt(len(channels[0])))
    f = int(sqrt(len(filters[0])))

    z_size = (w - f + 2*pad)/stride + 1
    z = np.zeros(z_size * z_size)
    for channel,f in zip(channels,filters):
        z += convolve(channel, f, stride, pad)

    return np.add(z,np.array([bias] * (z_size * z_size)))
