#include "select.h"
#include <stdlib.h>



Array create_array(int *A, int length)
{
	Array ret;
	ret.length = length;
	ret.A = A - 1;
	return ret;
}



void swap(Array Arr, int i, int j)
{
	if (i != j)
	{
		int *A = Arr.A;
		int tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;
	}
}


void insert(Array Arr, int j)
{
	int *A = Arr.A;
	int x = j;
	while ((x <= Arr.length) && (A[x - 1] >= A[x]))
	{
		swap(Arr, x - 1, x);
		x++;
	}
}	

void insertion_sort(Array Arr)
{
	int i;
	for (i = Arr.length - 1; i >= 1; i--)
	{
		insert(Arr, i + 1);
	}

}


int partition(Array Arr, int pivot)
{
	int first = Arr.A[1];
	int j;
	int i;
	for (i = 1; i <= Arr.length; i++)
	{
		if (Arr.A[i] == pivot)
		{
			swap(Arr, i, Arr.length);
		}
	}
	i = 0;
	for (j = 1; j <= Arr.length - 1; j++)
	{
		if (Arr.A[j] < pivot)
		{
			i++;
			swap(Arr, i, j);
		}
		if (Arr.A[j] == pivot)
		{
			Arr.A[j] = first;
		}	
	}
	swap(Arr, i + 1, Arr.length);
	return i + 1;
}

int select(Array Arr, int i)
{
	int m, n;
	int x, k;
	int five_array[5];
	Array group_of_five;
	int *Medians;
	Array median_of_medians;
	int sz = ((Arr.length + 4) / 5);

	if (Arr.length == 1)
	{
		return Arr.A[1];
	}
	
	Medians = malloc(sz * sizeof(int));
	
	for(m = 0; m < sz; m++)
	{

		group_of_five = create_array(Arr.A + 5 * m + 1, (m == sz - 1) ? (Arr.length % 5) ? Arr.length % 5 : 5 : 5);
		insertion_sort(group_of_five);
		Medians[m] = group_of_five.A[(group_of_five.length + 1) / 2];
	}
	median_of_medians = create_array(Medians, sz);
	x = select(median_of_medians, (sz + 1) / 2);
	free(Medians);
	k = partition(Arr, x);
	if (k == i)
	{
		return x;
	}
	if (k > i)
	{
		Arr.length = k;
		return select(Arr, i);
	}
	else
	{
		Arr.A = Arr.A + k;
		Arr.length = Arr.length - k;
		return select(Arr, i - k);
	}
}
	
		
	
	
