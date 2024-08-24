#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Function to flip the bits of a 32-bit unsigned integer
uint32_t flippingBits(uint32_t n) {
    // Define a variable num and set it to (2^32 - 1)
    uint32_t num = (1UL << 32) - 1;
    // Perform bitwise XOR operation between n and num to flip the bits
    return n ^ num;
}

// Function to handle input validation for positive integers
int readPositiveInteger(int *value) {
    char input[20]; // Buffer to store user input
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0; // Error reading input
    }
    if (sscanf(input, "%d", value) != 1 || *value <= 0) {
        return 0; // Invalid input
    }
    return 1; // Input is valid
}

int main() {
    int q;
    printf("Enter the number of test cases: ");
    if (!readPositiveInteger(&q)) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Iterate through each test case
    for (int i = 0; i < q; ++i) {
        uint32_t n;
        printf("Enter integer %d: ", i + 1);
        if (scanf("%u", &n) != 1) {
            printf("Invalid input for integer %d. Please enter a valid unsigned integer.\n", i + 1);
            return 1;
        }

        // Call the flippingBits function and store the result
        uint32_t result = flippingBits(n);

        // Print the result to output
        printf("Result for integer %d: %u\n", i + 1, result);
    }

    return 0;
}
