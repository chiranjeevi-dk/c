#include <stdio.h>
#include <ctype.h>

void record(char chararr[], int arr_size) {
    if (arr_size == 0) {
        printf("Count: 0\n");
        return;
    }

    int count = 0; // Start with 1 to account for the first character
    char current = tolower(chararr[0]);

    for (int i = 1; i < arr_size; i++) {
        char next = tolower(chararr[i]);
        if (current != next) {
            current = next;
            count++;
        }
    }

    printf("Count: %d\n", count);
}

int main() {
    printf("Enter the number of elements in the array: ");
    int array_size;
    scanf("%d", &array_size);

    // Consume the newline character left by scanf
    getchar();

    if (array_size <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    char chararr[array_size];
    printf("Enter the chars:\n");
    for (int i = 0; i < array_size; i++) {
        char ch;
        while (1) {
            ch = getchar();
            if (ch != '\n' && ch != ' ') {
                chararr[i] = ch;
                break;
            }
        }
    }

    record(chararr, array_size);

    return 0;
}
