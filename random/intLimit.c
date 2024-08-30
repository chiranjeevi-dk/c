#include <stdio.h>
#include <limits.h>

#define MIN_INT_VALUE INT_MIN
#define MAX_INT_VALUE INT_MAX

int get_integer(int *num) {
    printf("Enter an integer (between %d and %d): ", MIN_INT_VALUE, MAX_INT_VALUE);

    // Input validation with error handling
    if (scanf("%d", num) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return -1; // Return negative value to indicate error
    } else if (*num < MIN_INT_VALUE || *num > MAX_INT_VALUE) {
        fprintf(stderr, "Error: Value out of range. Please enter an integer between %d and %d.\n", MIN_INT_VALUE, MAX_INT_VALUE);
        return -2; // Return specific error code for range violation
    }

    return 0; // Return 0 on successful input
}

int main() {
    int num;

    int result = get_integer(&num);
    if (result != 0) {
        return 1; // Exit with error code if get_integer fails
    }

    printf("You entered: %d\n", num);

    return 0;
}