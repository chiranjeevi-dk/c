#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "darray.h"

int main() {
    // Create a dynamic array for integers
    darray_t *intArray = create_darray(2, sizeof(int), print_int);

    // Add elements to the array
    int value1 = 10;
    int value2 = 20;
    int value3 = 30;
    int value0 = 0;
    insert_darray(intArray, &value0);
    insert_darray(intArray, &value2);
    insert_darray(intArray, &value3);
    insert_at_darray(intArray, &value1, 1);

    // Print the array
    print_darray(intArray);

    // Free the dynamic array
    free_darray(intArray);

    return 0;
}