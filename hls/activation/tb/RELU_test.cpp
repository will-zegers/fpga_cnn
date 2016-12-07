#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "RELU.h"

#define SIZE 1024

DTYPE In[SIZE], Out[SIZE];

int main() {
	FILE *fp;
	for(int i=0; i<SIZE; i++)
	{
		In[i] = (i%2) ?  (float)sqrt((float)i) : (float)(-sqrt((float)i));
		RELU(&(In[i]), &(Out[i]));
	}
		//Perform Bit Reverse


	fp=fopen("out.dat", "w");
	printf("Printing bit reverse output\n");
	for(int i=0; i<SIZE; i++){
			printf("%d, %f, %f\n",i,In[i], Out[i]);
			fprintf(fp, "%d, %f, %f\n",i,In[i], Out[i]);
		}

		fclose(fp);

		//Check against golden output.
		printf ("Comparing against output data \n");
	  if (system("diff -w out.dat out.gold.dat")) {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
		fprintf(stdout, "*******************************************\n");
	     return 1;
	  } else {
		fprintf(stdout, "*******************************************\n");
		fprintf(stdout, "PASS: The output matches the golden output!\n");
		fprintf(stdout, "*******************************************\n");
	     return 0;
	  }


	}
