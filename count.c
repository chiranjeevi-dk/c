#include <stdio.h>

int main() {
    int start, end, divisor;
    scanf("%d %d %d", &start, &end, &divisor);

    int count = 0;
    int *ptr_count = &count;

    for (int i = start; i <= end; i++) {
        if (i % divisor == 0) (*ptr_count)++;
    }

    printf("%d\n", count);
    return 0;
}
