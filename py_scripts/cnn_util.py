import numpy as np

params = {
    'Input rows': 32,
    'Input cols': 32,
    'Input min value': 0,
    'Input max value': 10,
    'Output folder': './'
}


def generate_input(nRows, nCols, low, high, v_type=float):
    return np.array(
        [v_type(x) for x in np.random.uniform(low=low, high=high, size=nRows * nCols)]
    )


def get_user_param(msg, default):
    try:
        return int(raw_input(msg + ' [' + str(default) + ']: '))
    except ValueError:
        return default


def generate_weights(nRows, nCols, low=-1, high=1):
    return np.array(
        [i for i in np.random.uniform(low=low, high=high, size=nRows * nCols)]
    )


def generate_tb_files(X, golden, dir, weights=None, input_filename='input'):
    with open(dir + input_filename + '.dat', 'w') as input_dat:
        for x in X:
            input_dat.write(str(x) + '\n')
    with open(dir + 'out.gold.dat', 'w') as golden_dat:
        for g in golden:
            golden_dat.write(str(g) + '\n')
    if weights is not None:
        with open(dir + 'weights.dat', 'w') as weights_dat:
            for w in weights:
                weights_dat.write(str(w) + '\n')


def generate_golden(layer_func, *args):
    return layer_func(*args)
