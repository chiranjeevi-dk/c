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
    size_t capacity;
    size_t size;
    size_t element_size;
    void (*func_print)(void *element);

}darray_t;

darray_t *darray_create(size_t initial_capacity, size_t element_size, void (*func)(void *element));
void darray_free(darray_t *darray);
void darray_append(darray_t *darray, void *element);
void darray_insert_at(darray_t *darray, void *element, size_t position);
void darray_remove(darray_t *darray, void *element);
void darray_remove_at(darray_t *darray, size_t position);
int darray_resize(darray_t *darray, size_t new_capacity);
size_t get_size_t();
int ret_datatype(darray_t *darray);
void show_size(darray_t *darray);
void show_capacity(darray_t *darray);
int get_int();
float get_float();
double get_double();
char get_char();
char *get_string();
int compare(const void *a,const void *b, const int datatype);
void int_print(void *element);
void float_print(void *element);
void double_print(void *element);
void char_print(void *element);
void string_print(void *element);
void darray_print(darray_t *darray);

#endif