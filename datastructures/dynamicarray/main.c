#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "darray.h"

darray_t *create_gen_array(){
  
    int type,size;
    printf("\nEnter the following numbers to do\n1)Create an Int Array,\n2)Create an Float Array,\n3)Create an Double Array,\n4)Create an Char Array,\n5)Create an String Array.\n");
    printf("Enter the option : ");
    scanf("%d",&type);
    printf("\n");
    switch (type)
    {
    case 1:
        printf("Enter the initial size of int array : ");
        scanf("%d",&size);
        darray_t *int_array = darray_create(size, sizeof(int), int_print);
        printf("\nInteger array of size %d has been created. \n",size);
        return int_array;
        break;
    case 2:
        printf("Enter the initial size of float array : ");
        scanf("%d",&size);
        darray_t *float_array = darray_create(size, sizeof(float), float_print);
        printf("\nFloat array of size %d has been created. \n",size);
        return float_array;
        break;    
    case 3:
        printf("Enter the initial size of double array : ");
        scanf("%d",&size);
        darray_t *double_array = darray_create(size, sizeof(double), double_print);
        printf("\nDouble array of size %d has been created. \n",size);
        return double_array;
        break;
    case 4:
        printf("Enter the initial size of char array : ");
        scanf("%d",&size);
        darray_t *char_array = darray_create(size, sizeof(char), char_print);
        printf("\nChar array of size %d has been created. \n",size);
        return char_array;
        break;  
    case 5:
        printf("Enter the initial size of string array : ");
        scanf("%d",&size);
        printf("\nNote that max size of each string is 100 bytes.\n");
        darray_t *string_array = darray_create(size, 100 * sizeof(char), string_print);
        printf("\nString array of size %d has been created. \n",size);
        return string_array;
        break;
    default:
        printf("Enter a valid option generate an array.\n");
        return NULL;
        break;
    }

    return NULL;
}

void gen_array_append(darray_t *gen_array){

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
            char *str;
            printf("\nEnter the string value to be appended : ");
            str = get_string();
            //fgets(str,100 , stdin)getchar();
            darray_append(gen_array,&str);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

void gen_array_insert_at(darray_t *gen_array){
    
    int datatype = ret_datatype(gen_array);
    int position;
    switch(datatype){
        case 1:
            printf("\nEnter the integer value to be appended : ");
            int i_value;
            scanf("%d",&i_value);
            printf("\nEnter the position : ");
            scanf("%d",&position);
            darray_insert_at(gen_array,&i_value,position);
            break;
        case 2:
            printf("\nEnter the float value  to be appended : ");
            float f_value;
            scanf("%f",&f_value);
            printf("\nEnter the position : ");
            scanf("%d",&position);
            darray_insert_at(gen_array,&f_value,position);
            break;
        case 3:
            printf("\nEnter the double value to be appended : ");
            double d_value;
            scanf("%lf",&d_value);
            printf("\nEnter the position : ");
            scanf("%d",&position);
            darray_insert_at(gen_array,&d_value,position);
            break;
        case 4:
            char c_value;
            printf("\nEnter the char value to be appended : ");
            //Don't forget to use " %c" leading whitespace before %c to get correct input.
            scanf(" %c",&c_value);
            printf("\nEnter the position : ");
            scanf("%d",&position);
            darray_insert_at(gen_array,&c_value,position);
            break;
        case 5:
            printf("\nEnter the string value to be appended : ");
            //char str[100];
            char *str = malloc(100 * sizeof(char));
            scanf("%s",str);
            //fgets(str,100 * sizeof(char), stdin); 
            printf("\nEnter the position : ");
            scanf("%d",&position);
            darray_insert_at(gen_array,&str,position);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}

void gen_array_remove_at(darray_t *gen_array){

    int datatype = ret_datatype(gen_array);
    int position;

    switch(datatype){
        case 1:
            printf("\nEnter the integer index position to be Removed : ");
            scanf("%d",&position);
            darray_remove_at(gen_array,position);
            break;
        case 2:
            printf("\nEnter the float index position   to be Removed : ");
            scanf("%d",&position);
            darray_remove_at(gen_array,position);
            break;
        case 3:
            printf("\nEnter the double index position  to be Removed : ");
            scanf("%d",&position);
            darray_remove_at(gen_array,position);
            break;
        case 4:
            printf("\nEnter the char index position  to be Removed : ");
            scanf("%d",&position);
            darray_remove_at(gen_array,position);
            break;
        case 5:
            printf("\nEnter the string index position  to be Removed : ");
            scanf("%d",&position);
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
            int i_value;
            scanf("%d",&i_value);
            darray_remove(gen_array,&i_value);
            break;
        case 2:
            printf("\nEnter the float value  to be Removed : ");
            float f_value;
            scanf("%f",&f_value);
            darray_remove(gen_array,&f_value);
            break;
        case 3:
            printf("\nEnter the double value to be Removed : ");
            double d_value;
            scanf("%lf",&d_value);
            darray_remove(gen_array,&d_value);
            break;
        case 4:
            printf("\nEnter the char value to be Removed : ");
            char c_value;
            //Don't forget to use " %c" leading whitespace before %c to get correct input.
            scanf(" %c",&c_value);
            darray_remove(gen_array,&c_value);
            break;
        case 5:
            printf("\nEnter the string value to be Removed : ");
            //char str[100];
            char *str = malloc(100 * sizeof(char));
            //fgets(str,100 , stdin)getchar();
            scanf("%s",str);
            darray_remove(gen_array,&str);
            break;
        default:
            printf("\nEnter a valid option to append the value.\n");
            break;
    }
}


void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    darray_t *gen_array = NULL;
    int choice = 1;
    int option;

    while (choice) {
        printf("Enter the following numbers to do\n"
               "1) Create an Array\n"
               "2) Free an Array\n"
               "3) Print an Array\n"
               "4) Append in an Array\n"
               "5) Insert at particular Index in an Array\n"
               "6) Remove an Element\n"
               "7) Remove Element at Index\n");
        printf("Enter an option: ");
        
        if (scanf("%d", &option) != 1) {
            fprintf(stderr, "Error: Invalid input. Enter a number.\n");
            clear_input_buffer();
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
            default:
                fprintf(stderr, "Invalid option. Please try again.\n");
                break;
        }

        printf("\nEnter 1 if you want to proceed else 0: ");
        
        // Read and validate choice input
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Error: Invalid input. Enter a number.\n");
            clear_input_buffer();
            continue;
        }

        printf("\n");
    }

    return 0;
}