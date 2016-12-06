from cnn_util import  *
from cnn_funcs import mat_mul


if __name__ == '__main__':

    params.update({
        'Weights rows': 400,
        'Weights cols': 120,
        'Weights min value': -1,
        'Weights max value': 1,
    })

    for key in params.keys():
        params[key] = get_user_param(key, params[key])

    x = generate_input(
        params['Input rows'],
        params['Input cols'],
        params['Input min value'],
        params['Input max value'],
        v_type=int
    )

    w = generate_weights(
        params['Weights rows'],
        params['Weights cols'],
        params['Weights min value'],
        params['Weights max value']
    )

    golden = generate_golden(mat_mul, x, w)
    generate_tb_files(x, golden, params['Output folder'], weights=w)
