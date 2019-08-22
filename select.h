#ifndef __SELECT_H__
#define __SELECT_H__

#ifndef select_type
#define select_type char
#endif

typedef unsigned int array_index;
typedef array_index array_length;

typedef select_type array_element;

typedef struct {array_element *A; array_length length;} Array;

array_index my_select(Array, array_index);

#endif
