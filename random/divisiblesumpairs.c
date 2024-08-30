#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divisibleSumPairs(int n, int k, int ar_count, int* ar) {
    int total = 0;
    for (int i = 0; i < ar_count - 1; i++) {
        for (int j = i + 1; j < ar_count; j++) {
            if ((ar[i] + ar[j]) % k == 0)
                total++;
        }
    }
    return total;
}

int main() {
    int n, k;
    printf("Enter the number of elements in the array and the divisor (space-separated): ");
    scanf("%d %d", &n, &k);
    
    int* ar = (int*)malloc(n * sizeof(int));
    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }

    int result = divisibleSumPairs(n, k, n, ar);
    printf("Number of pairs divisible by %d: %d\n", k, result);
    
    free(ar);
    
    return 0;
}