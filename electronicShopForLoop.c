#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b) {
    int maximum = 0;
    bool maxExit = false;
    
    for (int keyboard = 0; keyboard < keyboards_count; keyboard++) {
        for (int drive = 0; drive < drives_count; drive++) {
            if (drives[drive] + keyboards[keyboard] <= b && drives[drive] + keyboards[keyboard] >= maximum) {
                maximum = drives[drive] + keyboards[keyboard];
                maxExit = true;
            }
        }
    }
    
    return maxExit ? maximum : -1;
}

int main() {
    int b; // budget
    int n; // number of keyboards
    int m; // number of drives
    
    // Open the input file
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }
    
    // Read inputs from the file
    fscanf(file, "%d %d %d", &b, &n, &m);

    // Allocate memory for arrays
    int* keyboards = (int*)malloc(n * sizeof(int));
    int* drives = (int*)malloc(m * sizeof(int));

    // Read keyboard prices
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &keyboards[i]);
    }

    // Read drive prices
    for (int i = 0; i < m; i++) {
        fscanf(file, "%d", &drives[i]);
    }

    // Calculate and print the maximum amount that can be spent
    int moneySpent = getMoneySpent(n, keyboards, m, drives, b);
    printf("%d\n", moneySpent);

    // Free allocated memory
    free(keyboards);
    free(drives);
    
    // Close the file
    fclose(file);

    return 0;
}

