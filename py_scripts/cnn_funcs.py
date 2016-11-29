import numpy as np
from math import sqrt


def convolve(X, weights, stride=1, pad=0):

    W = int(sqrt(len(X)))
    F = int(sqrt(len(weights)))

    X = np.reshape(X, (W,W))
    weights = np.reshape(weights, (F,F))

    if pad > 0:
        for i in range(pad):
            X = np.vstack(([0] * W, X, [0] * W))
        W += 2*pad
        X = np.array([np.hstack(([0 for j in range(pad)],X[i],[0 for j in range(pad)])) for i in range(W)])
        X = X.reshape(W,W)

    Z = []
    for i in range(0,W-F+1,stride):
        for j in range(0,W-F+1,stride):
            Z.append(sum([np.dot(w,x) for w,x in zip(weights,X[i:i+F,j:j+F])]))

    return np.array(Z)


def rectify(X, threshold = 0):
    return np.array([x if x > threshold else 0 for x in X])


def pool(X, pool_dmnin=2, stride=2, pooling_func=max):
    W = int(sqrt(len(X)))
    X = np.reshape(X, (W, W))

    Z = []
    for i in range(0,W,stride):
        for j in range(0,W,stride):
            Z.append(pooling_func([X[p][q] for p in range(i,i+stride) for q in range(j,j+stride)]))
    return Z