#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "darray.h"

darray_t *darray_create(int initial_capacity, size_t element_size, void(*print_func)(void *element)){
    /*
        First we need to allocate memory for Dynamic Array and then
        initial capacity using element size.
    */
   darray_t *darray = (darray_t *)malloc(sizeof(darray_t));

   if(darray == NULL){
    fprintf(stderr,"Error : Memory Allocation for Dynamic Array failed.");
    return NULL;
   }
   darray->capacity = initial_capacity;
   darray->element_size = element_size;
   darray->size = 0;
   darray->data = malloc(initial_capacity * element_size);
   if(darray->data == NULL){
    fprintf(stderr,"Error : Memory Allocation for Dynamic Array failed.");
    free(darray);
    return NULL;
   }
    darray->func_print = print_func;

    return darray;
}

void darray_free(darray_t *darray){
    if(darray != NULL){
    free(darray->data);
    free(darray);
    }
}

void darray_append(darray_t *darray, void *element){

    if(darray->size == darray->capacity){
        darray->capacity *= 2;
        darray->data = realloc(darray->data, darray->capacity * darray->element_size);
        if(darray->data == NULL){
            fprintf(stderr, "Error : Reallocation failed.\n");
            //free_darray(&darray);
            return;
        }
    }

    void *target = (char *)darray->data + (darray->size * darray->element_size);
    memcpy(target, element, darray->element_size);
    darray->size++;
    printf("\nElement has been appended.\n");
    darray_print(darray);
    printf("\n");
    
}

void darray_insert_at(darray_t *darray, void *element, int position){
    
    if(darray->size == darray->capacity){
        darray->capacity *= 2;
        darray->data = realloc(darray->data, darray->capacity * darray->element_size);
        if(darray->data == NULL){
            fprintf(stderr, "Error : Reallocation failed.\n");
            //free_darray(&darray);
            return;
        }
    }
     
    if(position < darray->size){
        void *target = (char *)darray->data + (position * darray->element_size);
        void *destination =(char *)darray->data + ((position +1 )* darray->element_size);
        /*
            Here Memmove is used to shift the elements from the source to destination
            and it also asks the size being shifted
        */
        memmove(destination, target, (darray->size - position) * darray->element_size);
    }else if(position > darray->capacity || (position ==  darray->capacity )){
        fprintf(stderr,"Error : The position you have entered is out of scope. \n");
        return;
    }
    
    void *target = (char *)darray->data + (position * darray->element_size);
    memcpy(target, element, darray->element_size);
    darray->size++;
    printf("\nElement has been inserted at desired position.\n");
    darray_print(darray);
    printf("\n");
}

void int_print(void *element){
    printf("%d ",*(int *)element);    
}

void float_print(void *element){
    printf("%f ",*(float *)element);    
}

void double_print(void *element){
    printf("%lf ",*(double *)element);    
}

void char_print(void *element){
    printf("%c ",*(char *)element);    
}

void string_print(void *element){
    printf("%s ",*(char **)element);    
}

void darray_print(darray_t *darray){

    if(darray == NULL || darray->data == NULL){
        fprintf(stderr, "Error : Dynamic Array not initialized.");
        return;
    }

    printf("Dynamic array is :\n");
    
    for(int i=0; i<darray->size; i++){
        void *element =(char *)darray->data + (i * darray->element_size);
        darray->func_print(element);
    }

    printf("\n");

}