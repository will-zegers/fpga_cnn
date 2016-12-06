from cnn_util import *
from cnn_funcs import pool


if __name__ == '__main__':

    funcdict = {
        'max': max,
        'average': np.mean,
        'mean': np.mean,
        'np.mean': np.mean
    }

    params.update({
        'Input min value': -10,
        'Input max value': 10,
        'Pool dimension': 2,
        'Stride': 2,
        'Pooling function': 'max'
    })

    for key in params.keys():
        params[key] = get_user_param(key, params[key])

    X = generate_input(
        params['Input rows'],
        params['Input cols'],
        params['Input min value'],
        params['Input max value'],
        v_type=float
    )
    golden = generate_golden(
        pool,
        X,
        params['Pool dimension'],
        params['Stride'],
        funcdict[params['Pooling function']]
    )
    generate_tb_files(X, golden, params['Output folder'])