#include <stdio.h>

#define MAX_PASSWORD_LENGTH 20

// Function to read password characters
void readPassword(char *password, int maxLength) {
    char ch;
    int i = 0;

    // Read characters until Enter key is pressed or maximum length is reached
    while ((ch = getch()) != '\r' && ch != EOF) {
        if (ch == '\b') { // Backspace handling
            if (i > 0) {
                printf("\b \b"); // Move cursor back, overwrite character, move cursor back again
                i--; // Decrement index
            }
            continue;
        }
        if (i < maxLength) { // Ensure buffer overflow doesn't occur
            password[i++] = ch; // Store character in password array
            putch('*'); // Print asterisk to represent character
        }
    }
    password[i] = '\0'; // Null-terminate the string
}

// Function to confirm password by re-entering it
int confirmPassword(char *password) {
    char confirm[MAX_PASSWORD_LENGTH + 1];

    printf("\n\nConfirm password: ");
    readPassword(confirm, MAX_PASSWORD_LENGTH);

    if (strcmp(password, confirm) == 0) {
        return 1; // Passwords match
    } else {
        printf("\nPasswords do not match. Please try again.\n");
        return 0; // Passwords do not match
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 for null terminator

    printf("Enter password: ");
    readPassword(password, MAX_PASSWORD_LENGTH);

    if (confirmPassword(password)) {
        printf("\nPassword set successfully: %s\n", password);
    } else {
        printf("\nPassword confirmation failed.\n");
    }

    return 0;
}
