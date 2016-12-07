#ifndef SOFTMAX_H
#define SOFTMAX_H

typedef float INPT_TYPE;
typedef float OUTP_TYPE;

const int SFMX_SIZE = 10;
const int RESOLUTION = 4000;

void softmax(INPT_TYPE Z[SFMX_SIZE], OUTP_TYPE P[SFMX_SIZE]);
#endif
