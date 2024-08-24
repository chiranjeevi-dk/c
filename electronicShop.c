#include <stdio.h>
#include <stdlib.h>

// Comparison function for sorting in ascending order
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int getMoneySpent(int keyboards_count, int* keyboards, int drives_count, int* drives, int b) {
    // Sort one of the arrays
    qsort(keyboards, keyboards_count, sizeof(int), compare_asc);

    int max_spent = -1; // Initialize to -1, assuming no combination is possible

    // Iterate through each drive
    for(int i = 0; i < drives_count; i++) {
        // Calculate the remaining budget after purchasing the current drive
        int remaining_budget = b - drives[i];
        
        // Binary search for the maximum affordable keyboard
        int low = 0, high = keyboards_count - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(keyboards[mid] <= remaining_budget) {
                // Update max_spent if current combination is greater
                if(keyboards[mid] + drives[i] > max_spent) {
                    max_spent = keyboards[mid] + drives[i];
                }
                // Move to the right to find a higher priced keyboard
                low = mid + 1;
            } else {
                // Move to the left
                high = mid - 1;
            }
        }
    }

    return max_spent;
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

