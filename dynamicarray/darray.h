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
    void (*func_print)(void *element);

}darray_t;

darray_t *darray_create(int initial_capacity, size_t element_size, void (*func)(void *element));
void darray_free(darray_t *darray);
void darray_append(darray_t *darray, void *element);
void darray_insert_at(darray_t *darray, void *element, int position);
void int_print(void *element);
void float_print(void *element);
void double_print(void *element);
void char_print(void *element);
void string_print(void *element);
void darray_print(darray_t *darray);

#endif