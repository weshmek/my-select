#ifndef __SELECT_H__
#define __SELECT_H__


/*
 * Here's our custom array structure. Instead of a standard C array with bounds [0, n - 1] where n is the number of elements,
 * this type of array is bounded by [1, n]. This makes heaps and other algorithmic data structures easier to implement.
 */
typedef struct {int *A; int length;} Array;


Array create_array(int *, int);

int select(Array, int);

void insertion_sort(Array);

int partition(Array, int);
#endif