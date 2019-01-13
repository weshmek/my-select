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
		if (Arr.A[i] > Arr.A[i + 1])
		{
			swap(Arr, i, i + 1);
			i++;
		}
		else
		{
			break;
		}
	}
}

static void insertion_sort(Array Arr)
{
	array_length l;
	for (l = Arr.length; l >= 1; l--)
	{
		insert(Arr, l);
	}
}


static array_index partition(Array Arr, array_index x)
{
	array_element pivot;
	array_index i, j;
	/*
	 * Place the pivot at the front of the array so we don't lose it
	 */
	swap(Arr, x, 1);
	pivot = Arr.A[1];
	j = 2;
	i = Arr.length;
	/* 
	 * Loop invariant: A[>i] >= pivot, A[>1,<j] < pivot
	 * Initial: j = 2, i = Arr.length, condition satisfied
	 * Maintenance: A[i] < pivot: swap(i, j) 
	 * 		=> A[j] < pivot
	 *		   j++ => A[>1,<j] < pivot
	 *		A[i] >= pivot:	i--
	 *		=> A[>i] >= pivot
	 * Termination: i <= j
	 *	=> A[j (>=i)] >= pivot
	 *	=> A[i  (>1,<= j)] <=  pivot
	 */
	do
	{
		if (Arr.A[i] < pivot)
		{
			swap(Arr, i, j++);
		}
		else
		{
			i--;
		}
	} while(i > j);
	/* This serves to prevent infinite loops if multiple entries with same value */
	if (Arr.A[j] >= pivot) 
	{
		j--;
	}
	swap(Arr, j, 1);
	return j;
}


array_index my_select(Array Arr, array_index i)
{

	Array medians;
	/* median of medians */
	array_index x;
	/* location of pivot after partition */
	array_index k;
	/* tail-call helper value; carries over new value of i to next loop iteration so we can set the state like a recursive call */
	array_index s = i;

	/* keeps track of number of times we've "shifted" the array */
	array_index offset = 0; 
	do
	{
		array_length j;
		array_length sz = (Arr.length % 5) ? Arr.length / 5 + 1 : Arr.length / 5;
	
			
	/*	if (Arr.length <= 5)
		{
			if (Arr.length < i) return -1;
			insertion_sort(Arr);
			return i;
		}
	*/	
		if (Arr.length == 1){
			//if (i != 0) return -1;
			return 1 + offset;
		//	return i;
		}
	
		i = s;
		
		for (j = 1; j <= sz; j++)
		{
			/*
			 * Divide the array into groups of 5, insertion sort each group.
			 * Take the median of group j, and place it at j in the original array. 
			 * This means we don't have to use any more space than was given for the array
			 */
			Array group_of_five;
			group_of_five.A = Arr.A + (j - 1) * 5;
			group_of_five.length = ((j == sz) && (Arr.length % 5)) ? Arr.length % 5 : 5;
			insertion_sort(group_of_five);
			swap(Arr, j, 5 * (j - 1) + group_of_five.length / 2 + group_of_five.length % 2);
		}

		/*
		 * Because the medians are placed at the front contiguously, we can re-use the space from the array
		 */
		medians.A = Arr.A;
		medians.length = sz;
	
		/*
		 * Select the median of medians
		 */
		x = my_select(medians, medians.length / 2);
		
		k = partition(Arr, x);
		
		if (k > i)
		{
			Arr.length = k;
		}
		if (k < i)
		{
			//"shift" the array to the left by k. Increase offset accordingly.
			Arr.A = Arr.A + k;
			offset += k;
			Arr.length = Arr.length - k;
			s = i - k;
		}
		/*
		 * Use tail-call optimization to "recursively" call select
		 */
	} while (i != k);
	return k + offset;
}
