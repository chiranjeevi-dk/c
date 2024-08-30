#include <stdio.h>


int main() {
    char password[20]; // Assuming maximum password length of 20 characters
    char ch;
    int i = 0;

    printf("Enter password: ");
    
    // Read characters until Enter key is pressed
    while ((ch = getch()) != '\r') { // '\r' represents the Enter key
        if (ch == '\b' && i > 0) { // Backspace handling
            printf("\b \b"); // Move cursor back, overwrite character, move cursor back again
            i--; // Decrement index
            continue;
        }
        password[i++] = ch; // Store character in password array
        printf("*"); // Print asterisk to represent character
    }
    password[i] = '\0'; // Null-terminate the string
    
    printf("\nPassword entered: %s\n", password); // Print entered password

    return 0;
}
