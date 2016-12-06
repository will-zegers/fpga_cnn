#ifndef POOLING_H
#define POOLING_H

typedef float DTYPE;
typedef int INTTYPE;

#define SIZE 28
#define F 2
#define S 2
#define DOWNSIZE (SIZE - F)/S + 1

void POOLING(DTYPE in[SIZE][SIZE], DTYPE out[DOWNSIZE][DOWNSIZE]);
DTYPE maxFour(DTYPE a, DTYPE b, DTYPE c, DTYPE d);
#endif
