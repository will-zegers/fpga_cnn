import numpy as np
from math import sqrt
from cnn_util import params


def convolve(X, weights, stride=1, pad=0):

    i_rows = params['Input rows']
    i_cols = params['Input cols']
    w_rows = params['Weights rows']
    w_cols = params['Weights cols']

    X = np.reshape(X, (i_rows, i_cols))
    weights = np.reshape(weights, (w_rows, w_cols))

    if pad > 0:
        for i in range(pad):
            X = np.vstack(([0] * (i_rows + 2*pad), X, [0] * (i_rows + 2*pad)))
        X = np.array([np.hstack(([0 for j in range(pad)], X[i], [0 for j in range(pad)])) for i in range(i_rows + 2*pad)])
        X = X.reshape(i_rows + 2*pad, i_cols + 2*pad)

    Z = []
    for i in range(0,stride+(i_rows-w_rows + 2*pad),stride):
        for j in range(0,stride+(i_rows-w_rows + 2*pad),stride):
            Z.append(sum([np.dot(r,c) for r,c in zip(weights,X[i:i+w_rows,j:j+w_cols])]))

    return np.array(Z)


def rectify(X, threshold = 0):
    return np.array([x if x > threshold else 0 for x in X])


def pool(X, pool_dmnin=2, stride=2, pooling_func=max):

    i_rows = params['Input rows']
    i_cols = params['Input cols']
    X = np.reshape(X, (i_rows, i_cols))

    Z = []
    for i in range(0, i_rows, stride):
        for j in range(0, i_cols, stride):
            Z.append(pooling_func([X[p][q] for p in range(i,i+pool_dmnin) for q in range(j,j+pool_dmnin)]))
    return Z


def mat_mul(x, w):
    x = np.reshape(x, (params['Input rows'], params['Input cols']))
    w = np.reshape(w, (params['Weights rows'], params['Weights cols']))
    return np.dot(x,w).flatten()

def sigmoid(x,w):
    return