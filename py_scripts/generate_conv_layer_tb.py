from cnn_util import *
from cnn_layers import convolution_layer


def generate_tb_files(channels, filters, golden, dir):
    for i in range(len(channels)):
        with open(dir + 'channel' + str(i) + '.dat', 'w') as channel_dat:
            for x in channels[i]:
                channel_dat.write(str(x) + '\n')

    for i in range(len(filters)):
        with open(dir + 'filter' + str(i) + '.dat', 'w') as filter_dat:
            for f in filters[i]:
                filter_dat.write(str(f) + '\n')

    with open(dir + 'out.gold.dat', 'w') as golden_dat:
        for g in golden:
            golden_dat.write(str(g) + '\n')


if __name__ == '__main__':

    CHANNEL_CNT = 3

    params.update({
        'Weights rows': 5,
        'Weights cols': 5,
        'Weights min value': -1,
        'Weights max value': 1,
        'Bias': 0,
        'Stride': 2,
        'Padding': 0,
    })

    for key in params.keys():
        params[key] = get_user_param(key, params[key])

    channels = []
    for i in range(CHANNEL_CNT):
        channels.append(generate_input(
            params['Input rows'],
            params['Input cols'],
            params['Input min value'],
            params['Input max value'],
            v_type=int)
        )

    filters = []
    for i in range(CHANNEL_CNT):
        filters.append(generate_weights(
            params['Weights rows'],
            params['Weights cols'],
            params['Weights min value'],
            params['Weights max value']
        ))

    golden = generate_golden(convolution_layer, channels, filters, params['Stride'], params['Padding'], params['Bias'])

    generate_tb_files(channels, filters, golden, params['Output folder'])
