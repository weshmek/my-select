#include "select.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	Array Arr;
	array_length l;
	array_element *A;
	printf("%d\n", argc);
	for (l = 1; l <= argc - 1; l++)
	{
		printf("%s\n", argv[l]);
	}
	A = malloc((argc - 1) * sizeof(array_element));
	Arr.A = A - 1;
	Arr.length = argc - 1;
	for (l = 1; l <= Arr.length; l++)
	{
		Arr.A[l] = (array_element) atoi(argv[l]);
	}
	for (l = 1; l <= Arr.length; l++)
	{
		printf("%f\t", Arr.A[l]);
	}
	printf("\n");
	for (l = 1; l <= Arr.length; l++)
	{
		printf("%f\t", select(Arr, l));
	}
	printf("\n");
	for (l = 1; l <= Arr.length; l++)
	{
		printf("%f\t", Arr.A[l]);
	}
	printf("\n");
	free(A);
	printf("\n");
	
}