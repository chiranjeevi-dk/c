#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Generic swap function using a void pointer
void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    printf("hello world\n");
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

int main() {
    int a = 10, b = 20;
    double c = 25.00, d = 35.6979489;
    char l = 'h', m = 'l';

    printf("Before swapping:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("c = %f, d = %f\n", c, d);
    printf("l = %c, m = %c\n", l, m);

    swap(&a, &b, sizeof(int));
    swap(&c, &d, sizeof(double));
    swap(&l, &m, sizeof(char));

    printf("\nAfter swapping:\n");
    printf("a = %d, b = %d\n", a, b);
    printf("c = %f, d = %f\n", c, d);
    printf("l = %c, m = %c\n", l, m);

    return 0;
}