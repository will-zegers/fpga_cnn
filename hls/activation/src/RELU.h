#ifndef RELU_H
#define RELU_H

typedef float DTYPE;
typedef int INTTYPE;

const int nROWS = 400;
const int nCOLS = 120;

void RELU(DTYPE in[nROWS][nCOLS], DTYPE out[nROWS][nCOLS]);

#endif
