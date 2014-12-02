#ifndef __SELECT_H__
#define __SELECT_H__

typedef double array_element;
typedef unsigned long array_length;
typedef array_length array_index;

typedef struct {array_element *A; array_length length;} Array;


array_element select(Array, array_length);
#endif