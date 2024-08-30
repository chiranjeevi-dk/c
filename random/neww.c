#include <stdio.h>

int main() {
    int a = 15; // Binary: 0000 0000 0000 1111 (in 4 bytes: 00000000 00000000 00000000 00001111)
    int *p1 = &a;  // p1 is an int pointer pointing to 'a'
    char *p2 = (char *)&a;  // p2 is a char pointer pointing to 'a'

    // Printing the address of 'a' using %p (pointer format specifier) instead of %d
    printf("a loc = %d\n", &a);

    // Printing the value and location of 'p1'
    printf("p1: %d   loc = %d \n", *p1, p1);

    // Printing the value and location of 'p2'
    printf("p2: %d   loc = %d \n", *p2, p2);

    return 0;
}