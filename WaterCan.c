#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define START_INDEX 1

int main() {
    int arraySize;
    scanf("%d", &arraySize);

    int *indexMap = (int *)malloc((arraySize + 1) * sizeof(int));
    for (int i = 1; i <= arraySize; i++) {
        int key, value;
        scanf("%d", &key);
        value = i;
        indexMap[key] = value;
    }

    long long cost;
    scanf("%lld", &cost);

    long long total = (long long)indexMap[START_INDEX] * cost;

    printf("%lld ", total);
    for (int k = START_INDEX; k < arraySize; k++) {
        int current = indexMap[k];
        int next = indexMap[k + 1]; // Handling missing values (assuming all keys are present)
        total += labs(next - current) * cost;
        printf("%lld ", total);
    }
    printf("\n");
    free(indexMap);
    return 0;
}

