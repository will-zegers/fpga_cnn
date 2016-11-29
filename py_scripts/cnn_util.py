import numpy as np

params = {
    'Input dimension': 8,
    'Input min value': 0,
    'Input max value': 10,
    'Output folder': './'
}


def generate_input(dimension, low, high, v_type=float):
    return np.array(
        [v_type(x) for x in np.random.uniform(low=low, high=high, size=dimension * dimension)]
    )


def get_user_param(msg, default):
    try:
        return int(raw_input(msg + ' [' + str(default) + ']: '))
    except ValueError:
        return default


def generate_kernel(dimension=3, low=-1, high=1):
    return np.array(
        [i for i in np.random.uniform(low=low, high=high, size=dimension * dimension)]
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
