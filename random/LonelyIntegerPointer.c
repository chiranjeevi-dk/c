#include <stdio.h>
#include <stdlib.h>

int lonelyInteger(int arr[], int size) {
    int result = 0;
    int *ptr = NULL;
    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == result) {
            ptr = &arr[i];
            break;
        }
    }
    if (ptr != NULL) {
        printf("The location of the lonely integer is: %p %p\n", ptr,ptr+1);
    } else {
        printf("The lonely integer was not found in the array.\n");
    }
    return result;
}

int main() {
    int size;

    // Read the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for the array
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Prompt the user to enter each element of the array
    printf("Enter %d elements for the array:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Print the elements of the array
    printf("The array you entered is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the lonelyInteger function
    int result = lonelyInteger(arr, size);
    printf("The lonely integer is: %d\n", result);

    // Free the dynamically allocated memory
    free(arr);

    return 0;
}