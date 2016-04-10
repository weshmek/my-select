#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	array_index i;
	Array Arr;
	array_element A[10];
	srand(getpid());
	for (i = 0; i < sizeof(A) / sizeof(A[0]); i++)
	{
		A[i] = (array_element) (rand() %100) / (array_element)(rand() % 100);
		printf("%f ", A[i]);
	}
	printf("\n");
	Arr.A = A - 1;
	Arr.length = sizeof(A) / sizeof(A[0]);
	for (i = 1; i <= Arr.length; i++)
	{
		array_index k = my_select(Arr, i);
		printf("%d: %f at %d\n", (int)i, Arr.A[k], (int)k);
	}
	return 0;
}
