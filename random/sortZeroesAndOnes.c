#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int size) {
    printf("Input array: [");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i != size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void sortZeroesAndOnes(int* array, int size) {
    int* sortedArray = (int*)malloc(size * sizeof(int));
    int zeroIndex = 0;
    int oneIndex = size - 1;

    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            sortedArray[zeroIndex] = 0;
            zeroIndex++;
        } else if (array[i] == 1) {
            sortedArray[oneIndex] = 1;
            oneIndex--;
        }
    }

    // Copy sorted array back to original array
    for (int i = 0; i < size; i++) {
        array[i] = sortedArray[i];
    }

    free(sortedArray);
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Could not open input file.\n");
        return 1;
    }

    int size;
    fscanf(file, "%d", &size);

    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);

    // Print input array and its size
    printArray(array, size);
    printf("Input size: %d\n", size);

    sortZeroesAndOnes(array, size);

    printf("Sorted list:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);

    return 0;
}