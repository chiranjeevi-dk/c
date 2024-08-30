#include <stdio.h>
#include <stdlib.h>

void rotate(int arr1[], int arr2[], int arr_size) {
    int output[arr_size];
    int index = 0;

    for (int times = 0; times < arr_size; times++) {
        int temp = arr1[0];
        for (int i = 0; i < arr_size - 1; i++) {
            arr1[i] = arr1[i + 1];
        }
        arr1[arr_size - 1] = temp;

        int sum = 0;
        for (int i = 0; i < arr_size; i++) {
            sum += abs(arr1[i] - arr2[i]);
        }
        output[index++] = sum;
    }
    printf("Enter the number of elements in the array: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", output[i]);
    }
    printf("\n");
}

int main() {
    printf("Enter the number of elements in the array: ");
    int arr_size;
    scanf("%d", &arr_size);

    int *arr1 = (int *)malloc(arr_size * sizeof(int));
    int *arr2 = (int *)malloc(arr_size * sizeof(int));

    printf("Enter the array1 elements: ");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the array2 elements: ");
    for (int i = 0; i < arr_size; i++) {
        scanf("%d", &arr2[i]);
    }

    rotate(arr1, arr2, arr_size);
    
    free(arr1);
    free(arr2);

    return 0;
}