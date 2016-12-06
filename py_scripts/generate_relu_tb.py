from cnn_util import  *
from cnn_funcs import rectify


if __name__ == '__main__':

    params.update({
        'Input min value': -1,
        'Input max value': 1,
        'Threshold': 0
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
    golden = generate_golden(rectify, X, params['Threshold'])
    generate_tb_files(X, golden, params['Output folder'])
