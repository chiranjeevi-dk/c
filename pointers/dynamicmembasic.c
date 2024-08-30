#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamically allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    *ptr = 10; // Assign value 10 to the memory location pointed to by ptr
    printf("Address stored in ptr: %p\n", (void *)ptr); // Print the address stored in ptr
    printf("Value at memory location: %d\n", *ptr); // Print the value at the memory location

    int a = *ptr; // Assign the value stored at that memory location to variable a
    printf("Value of a: %d\n", a); // Print the value of a

    // Free dynamically allocated memory
    free(ptr);

    return 0;
}