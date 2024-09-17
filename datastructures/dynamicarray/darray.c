#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "darray.h"

darray_t *darray_create(size_t initial_capacity, size_t element_size, void(*print_func)(void *element)){
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

void show_size(darray_t *darray){
    if(darray != NULL){
        printf("%zu ", darray->size);
    }
}

void show_capacity(darray_t *darray){
    if(darray != NULL){
        printf("%zu ", darray->capacity);
    }
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

    if(darray == NULL){
        fprintf(stderr, "Error: Dynamic array is NULL.\n");
        return;
    }

    if(darray->data == NULL){
        fprintf(stderr, "Error: Dynamic array data is uninitialized.\n");
        return;
    }


    printf("Dynamic array is :\n");
    
    for(size_t i=0; i<darray->size; i++){
        void *element =(char *)darray->data + (i * darray->element_size);
        darray->func_print(element);
    }

    printf("\n");

}

int ret_datatype(darray_t *darray){

    int datatype = 0;

    if(darray->func_print == int_print){
        datatype = 1;
    }else if(darray->func_print == float_print){
        datatype = 2;
    }else if(darray->func_print == double_print){
        datatype = 3;
    }else if(darray->func_print == char_print){
        datatype = 4;
    }else if(darray->func_print == string_print){
        datatype = 5;
    }else{
        fprintf(stderr,"Error : Couldnt figure out what data type. \n");
    }

    return datatype;
}

int darray_resize(darray_t *darray, size_t new_capacity){
    void **temp = realloc(darray->data, new_capacity * darray->element_size);
        if(temp== NULL){
            fprintf(stderr, "Error : Reallocation failed.\n");
            //free_darray(&darray);
            return 0;
        }
    darray->data = temp;
    darray->capacity = new_capacity;
    return 1;    
}

void darray_append(darray_t *darray, void *element){

    if(darray->size == darray->capacity){
        if(darray_resize(darray, darray->capacity * 2) != 1){
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

void darray_insert_at(darray_t *darray, void *element, size_t position){
    
    if(darray->size == darray->capacity){
        if(darray_resize(darray, darray->capacity * 2) != 1){
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

int compare(const void *a, const void *b, const int datatype){

    switch(datatype){
        case 1:
            if (*(int *)a == *(int *)b)
                return 0;
            else
                return 1;
            break;
        case 2:
            if (*(float *)a == *(float *)b)
                return 0;
            else
                return 1;
            break;
        case 3:
            if (*(double *)a == *(double *)b)
                return 0;
            else
                return 1;
            break;
        case 4:
            if (*(char *)a == *(char *)b)
                return 0;
            else
                return 1;
            break;
        case 5:
            a = *(char **)a;
            b = *(char **)b;
            return strcmp(a,b);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }

    return 1;
}

void darray_remove(darray_t *darray, void *element){

    int index = -1;
    int datatype = ret_datatype(darray);

    for(size_t i = 0; i < darray->size ; i++){
        void *temp = (char *)darray->data + (i * darray->element_size);
        int result = compare(element,temp,datatype);

        if(result == 0){
            index = i;
        }
    }

    if(index == -1){    
        fprintf(stderr,"Error : Element not found.");
        return;
    }else if(index == 0 && darray->size == 1){
        darray_free(darray);
        printf("\nThe desired Element has been removed.\n");
        return;
    }else{
        void *destination = (char *)darray->data + (index * darray->element_size);
        void *target =(char *)darray->data + ((index +1 )* darray->element_size);
        /*
            Here Memmove is used to shift the elements from the source to destination
            and it also asks the size being shifted
        */
        memmove(destination, target, (darray->size - index-1) * darray->element_size);
    }
    darray->size--;
    printf("\nThe desired Element has been removed.\n");
    darray_print(darray);
    printf("\n");
}

void darray_remove_at(darray_t *darray, size_t position){

    if(position == -1){    
        fprintf(stderr,"Error : Element not found.");
        return;
    }else if(position == 0 && darray->size == 1){
        darray_free(darray);
        printf("\nThe desired Element has been removed.\n");
        return;
    }else{
        void *destination = (char *)darray->data + (position * darray->element_size);
        void *target =(char *)darray->data + ((position +1 )* darray->element_size);
        /*
            Here Memmove is used to shift the elements from the source to destination
            and it also asks the size being shifted
        */
        memmove(destination, target, (darray->size - position-1) * darray->element_size);
    }
    darray->size--;
    printf("\nThe desired Element has been removed.\n");
    darray_print(darray);
    printf("\n");
}

int get_int(){
    int value;
    char ch;
    while(1){
        if(scanf("%d",&value)==1){
            if(scanf("%c", &ch)==1 && ch!='\n'){
                fprintf(stderr, "\nError :Invalid input.Enter an Integer\n");
                while((ch = getchar()) != '\n' && ch != EOF);
            }else{
                return value;
            }
        }else{
            fprintf(stderr, "\nError :Invalid input. Enter an Integer.\n");
            while((ch =getchar()) != '\n' && ch != EOF);
        }
    }
}

float get_float(){
    float value;
    char ch;
    while(1){
        if(scanf("%f",&value)==1){
            if(scanf("%c", &ch)==1 && ch!='\n'){
                fprintf(stderr, "\nError :Invalid input.Enter an Float\n");
                while((ch = getchar()) != '\n' && ch != EOF);
            }else{
                return value;
            }
        }else{
            fprintf(stderr, "\nError :Invalid input. Enter an Float.\n");
            while((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

double get_double(){
    double value;
    char ch;
    while(1){
        if(scanf("%lf",&value)==1){
            if(scanf("%c", &ch)==1 && ch!='\n'){
                fprintf(stderr, "\nError :Invalid input. Enter an double.\n");
                while((ch = getchar()) != '\n' && ch != EOF);
            }else{
                return value;
            }
        }else{
            fprintf(stderr, "\nError :Invalid input. Enter an double.\n");
            while((ch = getchar()) != '\n' && ch != EOF);
        }
    }
}

char get_char(){
    char value;
    char ch;
    while(1){
        if(scanf(" %c",&value)==1){
            if(scanf("%c", &ch)==1 && ch!='\n'){
                fprintf(stderr, "\nError :Invalid input. Enter an Char.\n");
                while((ch = getchar()) != '\n' && ch != EOF);
            }else{
                return value;
            }
        }else{
            fprintf(stderr, "\nError :Invalid input. Enter an Char.\n");
            while((ch =getchar()) != '\n' && ch != EOF);
        }
    }
}

size_t get_size_t(){
    size_t value;
    char ch;
    while(1){
        if(scanf("%zu",&value)==1){
            if(scanf("%c", &ch)==1 && ch!='\n'){
                fprintf(stderr, "\nError :Invalid input.Enter an Integer\n");
                while((ch = getchar()) != '\n' && ch != EOF);
            }else{
                return value;
            }
        }else{
            fprintf(stderr, "\nError :Invalid input. Enter an Integer.\n");
            while((ch =getchar()) != '\n' && ch != EOF);
        }
    }
}


char *get_string(){
    char *buffer = (char *)malloc(100 * sizeof(char));
    
    if (buffer == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    
    while(1){
        if(fgets(buffer, 100, stdin) != NULL){
            size_t len = strlen(buffer);
            if(len > 0 && buffer[len-1] == '\n'){
                buffer[len-1] = '\0';  // Remove newline
            }else{
                // Clear the buffer in case the input was too long
                int c;
                while((c = getchar()) != '\n' && c != EOF);
            }
            return buffer;
        } else {
            fprintf(stderr, "\nError: Invalid input.\n");
            int c;
            // Clear the buffer before retrying
            while((c = getchar()) != '\n' && c != EOF);
        }
    }
}

