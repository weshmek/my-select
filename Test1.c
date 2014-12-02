#include "select.h"
#include <stdio.h>

int main()
{
	array_index i;
	Array Arr;
	array_element A []= { 9, 0, 2, 10, 55, 23, 21 };
	Arr.A = A - 1;
	Arr.length = sizeof(A) / sizeof(A[0]);
	for (i = 1; i <= Arr.length ; i++)
	{
		printf("%f\t", Arr.A[i]);
	}
	printf("\n");
	for (i = 1; i <= Arr.length ; i++)
	{
		printf("%f\t", select(Arr, i));
	}
	printf("\n");
}		