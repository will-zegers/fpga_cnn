from cnn_util import *
from cnn_funcs import convolve


if __name__ == '__main__':

    params.update({
        'Kernel dimension': 3,
        'Kernel min value': -1,
        'Kernel max value': 1,
        'Bias': 1,
        'Stride': 2,
        'Padding': 0
    })

    for key in params.keys():
        params[key] = get_user_param(key, params[key])

    X = generate_input(
        params['Input dimension'],
        params['Input min value'],
        params['Input max value'],
        v_type=int
    )

    weights = generate_kernel(
        params['Kernel dimension'],
        params['Kernel min value'],
        params['Kernel max value']
    )

    golden = generate_golden(convolve, X, weights, params['Stride'], params['Padding'])

    generate_tb_files(X, golden, params['Output folder'], weights=weights)
