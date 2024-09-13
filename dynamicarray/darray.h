/* Header file for  Dynamic Array using C;
   implementing with the basic knowledge i have on pointers, struct and dynamic memory allocation.
   starting this on 12th september
*/

#ifndef DARRAY_H
#define DARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct darray
{
    /* 
        The dynamic array should have the pointer to the head and tail of the array,
        it should also have the capacity and size so that we can easily have a track.
    */
    void **data;
    int capacity;
    int size;
    size_t element_size;
    void (*print_func)(void *element);

}darray_t;

darray_t *create_darray(int initial_capacity, size_t element_size, void (*print_func)(void *element));
void free_darray(darray_t *darray);
void insert_darray(darray_t *darray, void *element);
void insert_at_darray(darray_t *darray, void *element, int position);
void print_int(void *element);
void print_float(void *element);
void print_double(void *element);
void print_char(void *element);
void print_string(void *element);
void print_darray(darray_t *darray);

#endif