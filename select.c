#include "select.h"



static void swap(Array Arr, array_index i, array_index j)
{
	array_element tmp = Arr.A[i];
	Arr.A[i] = Arr.A[j];
	Arr.A[j] = tmp;
}

static void insert(Array Arr, array_index i)
{
	while (i < Arr.length)
	{
		if (Arr.A[i] >= Arr.A[i + 1])
		{
			swap(Arr, i, i + 1);
		}
		else
		{
			break;
		}
		i++;
	}
}

static void insertion_sort(Array Arr)
{
	array_index i;
	for (i = Arr.length ; i > 0; i--)
	{
		insert(Arr, i);
	}
}



static array_index partition(Array Arr, array_element pivot)
{
	array_index j = 2;
	array_length i = 1;
	while (Arr.A[i] != pivot)
	{
		i++;
	}
	swap(Arr, i, 1);
	i = Arr.length;
	do
	{
		if (Arr.A[i] < pivot) 
		{
			swap(Arr, i, j);
			j++;	
		}
		else
		{
			i--;
		}
	} while (i > j);
	if (Arr.A[j] >= pivot)
	{
		j--;
	}
	swap(Arr, 1, j);
	return j;
}



array_element select(Array Arr, array_index i)
{
	array_index k;
	array_element x;
	array_index s = i;
	do
	{
		array_index j;
		array_length sz;
		Array medians;
		if (Arr.length == 1)
		{
			return Arr.A[1];
		}
		i = s;
		sz = (Arr.length % 5) ? (Arr.length / 5) + 1 : (Arr.length / 5);

		

		for (j = 1; j <= sz; j++)
		{
			Array group_of_five;
			group_of_five.A = Arr.A + 5 * (j - 1);
			group_of_five.length = ((j == sz) && ((Arr.length % 5) != 0)) ? Arr.length % 5 : 5;
			insertion_sort(group_of_five);
			swap(Arr, j, (5 * (j - 1)) + (group_of_five.length / 2) + (group_of_five.length % 2));
		}
		medians.A = Arr.A;
		medians.length = sz;
					 
		x = select(medians, medians.length >> 1);
	
		k = partition(Arr, x);
	
		if (k > i)
		{
			Arr.length = k;
		}
		else if (k < i)
		{
		
			Arr.A = Arr.A + k;
			Arr.length = Arr.length - k;
			s = i - k;
		}
	}while (i != k); /*Tail-Call Optimization!*/
	return x;
}
