#ifndef __SELECT_H__
#define __SELECT_H__

typedef unsigned long array_index;
typedef array_index array_length;

typedef float array_element;

typedef struct {array_element *A; array_length length;} Array;

array_index my_select(Array, array_index);

#endif
