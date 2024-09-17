#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "darray.h"

size_t get_size_input(const char *prompt){
    size_t size;
    printf("%s",prompt);
    size = get_size_t();
    return size;
}

darray_t *create_array_helper(size_t element_size, void (*func_print)(void *element)){
    size_t size = get_size_input("\nEnter the size of the Initial Array : ");
    darray_t *array = darray_create(size, element_size, func_print);
    printf("\nArray of size %zu has been created.\n", size);
    return array;
}

darray_t *create_gen_array(){
  
    int type;
    printf("\nEnter the following numbers to do\n1)Create an Int Array,\n2)Create an Float Array,\n3)Create an Double Array,\n4)Create an Char Array,\n5)Create an String Array.\n");
    printf("\nEnter the option : ");
    scanf("%d",&type);

    switch (type) {
        case 1:
            return create_array_helper(sizeof(int), int_print);
        case 2:
            return create_array_helper(sizeof(float), float_print);
        case 3:
            return create_array_helper(sizeof(double), double_print);
        case 4:
            return create_array_helper(sizeof(char), char_print);
        case 5: {
            printf("Note: Max size of each string is 100 bytes.\n");
            return create_array_helper(100 * sizeof(char), string_print);
        }
        default:
            printf("Invalid option. Please try again.\n");
            return NULL;
    }

    return NULL;
}

void flush_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  
}

void gen_array_append(darray_t *gen_array){
    
    if (!gen_array) {
        fprintf(stderr, "Error: No array to append to.\n");
        return;
    }

    int datatype = ret_datatype(gen_array);

    switch(datatype){
        case 1:
            printf("\nEnter the integer value to be appended : ");
            int i_value = get_int();
            darray_append(gen_array,&i_value);
            break;
        case 2:
            printf("\nEnter the float value  to be appended : ");
            float f_value = get_float();
            darray_append(gen_array,&f_value);
            break;
        case 3:
            printf("\nEnter the double value to be appended : ");
            double d_value = get_double();
            darray_append(gen_array,&d_value);
            break;
        case 4:
            printf("\nEnter the char value to be appended : ");
            char c_value = get_char();
            //Don't forget to use " %c" leading whitespace before %c to get correct input.
            darray_append(gen_array,&c_value);
            break;
        case 5:
            printf("\nEnter the string value to be appended : ");
            flush_input_buffer();
            char *str;
            str = get_string();
            darray_append(gen_array,&str);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

void gen_array_insert_at(darray_t *gen_array){
    
    int datatype = ret_datatype(gen_array);
    size_t position;
    switch(datatype){
        case 1:
            printf("\nEnter the integer value to be appended : ");
            int i_value = get_int();
            printf("\nEnter the position : ");
            position = get_size_t();
            darray_insert_at(gen_array,&i_value,position);
            break;
        case 2:
            printf("\nEnter the float value  to be appended : ");
            float f_value = get_float();
            scanf("%f",&f_value);
            printf("\nEnter the position : ");
            position = get_size_t();
            darray_insert_at(gen_array,&f_value,position);
            break;
        case 3:
            printf("\nEnter the double value to be appended : ");
            double d_value = get_double();
            printf("\nEnter the position : ");
            position = get_size_t();
            darray_insert_at(gen_array,&d_value,position);
            break;
        case 4:
            printf("\nEnter the char value to be appended : ");
            char c_value = get_char();
            //Don't forget to use " %c" leading whitespace before %c to get correct input.
            printf("\nEnter the position : ");
            position = get_size_t();
            darray_insert_at(gen_array,&c_value,position);
            break;
        case 5:
            printf("\nEnter the string value to be appended : ");
            flush_input_buffer();
            char *str;
            str = get_string();
            printf("\nEnter the position : ");
            position = get_size_t();
            darray_insert_at(gen_array,&str,position);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

void gen_array_remove_at(darray_t *gen_array){

    int datatype = ret_datatype(gen_array);
    size_t position;

    switch(datatype){
        case 1:
            printf("\nEnter the integer index position to be Removed : ");
            position = get_size_t();
            darray_remove_at(gen_array,position);
            break;
        case 2:
            printf("\nEnter the float index position   to be Removed : ");
            position = get_size_t();
            darray_remove_at(gen_array,position);
            break;
        case 3:
            printf("\nEnter the double index position  to be Removed : ");
            position = get_size_t();
            darray_remove_at(gen_array,position);
            break;
        case 4:
            printf("\nEnter the char index position  to be Removed : ");
            position = get_size_t();
            darray_remove_at(gen_array,position);
            break;
        case 5:
            printf("\nEnter the string index position  to be Removed : ");
            position = get_size_t();
            darray_remove_at(gen_array,position);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

void gen_array_remove(darray_t *gen_array){

    int datatype = ret_datatype(gen_array);

    switch(datatype){
        case 1:
            printf("\nEnter the integer value to be Removed : ");
            int i_value = get_int();
            darray_remove(gen_array,&i_value);
            break;
        case 2:
            printf("\nEnter the float value  to be Removed : ");
            float f_value = get_float();
            darray_remove(gen_array,&f_value);
            break;
        case 3:
            printf("\nEnter the double value to be Removed : ");
            double d_value = get_double();
            darray_remove(gen_array,&d_value);
            break;
        case 4:
            printf("\nEnter the char value to be Removed : ");
            char c_value = get_char();
            darray_remove(gen_array,&c_value);
            break;
        case 5:
            printf("\nEnter the string value to be Removed : ");
            flush_input_buffer();
            char *str;
            str = get_string();
            darray_remove(gen_array,&str);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

int main() {
    darray_t *gen_array = NULL;
    int choice = 1;
    int option;

    while (choice) {
        printf("\nEnter the following numbers to do\n"
               "1) Create an Array\n"
               "2) Free an Array\n"
               "3) Print an Array\n"
               "4) Append in an Array\n"
               "5) Insert at particular Index in an Array\n"
               "6) Remove an Element\n"
               "7) Remove Element at Index\n"
               "8) Get size of the Array\n"
               "9) Get capacity of the Array\n");
        printf("Enter an option: ");
        printf("\n"); 
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Error: Invalid input. Enter a number.\n");
            flush_input_buffer();
            continue;
        }
        
        switch (option) {
            case 1:
                gen_array = create_gen_array();
                printf("The array has been created.\n");
                break;
            case 2:
                if (gen_array != NULL) {
                    darray_free(gen_array);
                    gen_array = NULL; // Avoid dangling pointer
                    printf("The array has been freed.\n");
                } else {
                    fprintf(stderr, "Error: No array to be freed.\n");
                }
                break;
            case 3:
                if (gen_array != NULL) {
                    darray_print(gen_array);
                    printf("The array has been printed.\n");
                } else {
                    fprintf(stderr, "Error: No array to print.\n");
                }
                break;
            case 4:
                if (gen_array != NULL) {
                    gen_array_append(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to append to.\n");
                }
                break;
            case 5:
                if (gen_array != NULL) {
                    gen_array_insert_at(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to insert at desired position.\n");
                }
                break;
            case 6:
                if (gen_array != NULL) {
                    gen_array_remove(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to remove an element from.\n");
                }
                break;
            case 7:
                if (gen_array != NULL) {
                    gen_array_remove_at(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to remove an element at specific index.\n");
                }
                break;
            case 8:
                if (gen_array != NULL) {
                    printf("The size of the array is : ");
                    show_size(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to get size.\n");
                }
                break;
            case 9:
                if (gen_array != NULL) {
                    printf("The capacity of the array is : ");
                    show_capacity(gen_array);
                } else {
                    fprintf(stderr, "Error: No array to get capacity.\n");
                }
                break;
            default:
                fprintf(stderr, "Invalid option. Please try again.\n");
                break;
        }

        printf("\n\nEnter 1 if you want to proceed else 0: ");
        
        // Read and validate choice input
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "\nError: Invalid input. Enter a number.\n");
            flush_input_buffer();
            continue;
        }

        printf("\n");
    }

    return 0;
}