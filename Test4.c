#include <stdio.h>
#include "select.h"


int main()
{
	int i;
	int A[] = {12, 15, 10, 19, 17, 24, 9, 55, 42, 64, 37, 89, 88, 40};
	Array B = create_array(A, sizeof(A)/sizeof(A[0]));
	for (i = 0; i < sizeof(A)/sizeof(A[0]); i++)
	{
		printf("%d\t", select(B, i + 1));
	}
	printf("\n");
}