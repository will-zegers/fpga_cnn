#include "testClass.h"
#include <stdio.h>

Test_Layer::Test_Layer printArray(int myArray[Test_Layer::mArraySize]) {
	int i;

	for (i = 0; i < mArraySize; ++i) {
		printf("%d\n", myArray[i]);
	}
}
