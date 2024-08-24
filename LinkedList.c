#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a type alias for node data for clarity
typedef int data_type;

struct Node {
  data_type data;
  struct Node* next;
};

// Function to create a new node
struct Node* createNode(data_type data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  if (newNode == NULL) {
    fprintf(stderr, "Memory allocation failed. Exiting.\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to get user input for a new node's data with input validation
data_type getUserInput() {
  data_type data;
  int scanf_result;
  bool validInput = false;
  while (!validInput) {
    printf("Enter data for the node (integer): ");
    scanf_result = scanf("%d", &data);
    if (scanf_result != 1) {
      // Clear the input buffer to avoid issues in the next loop iteration
      scanf("%*[^\n]");  // Read and discard characters until newline
      printf("Invalid input. Please enter an integer.\n");
    } else {
      validInput = true;
    }
  }
  return data;
}

// Function to print the linked list
void printList(struct Node* head) {
  if (head == NULL) {
    printf("The list is empty.\n");
    return;
  }

  printf("Linked List: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct Node* head = NULL; // Initially an empty linked list

  printf("Welcome to the Linked List program!\n");

  int choice = 1;
  while (choice != 0) {
    printf("\n1. Add Node\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");

    // Check if scanf successfully reads an integer
    if (scanf("%d", &choice) != 1) {
      // Clear the input buffer
      scanf("%*[^\n]");
      printf("Invalid input. Please enter 1 or 0.\n");
      continue;
    }

    if (choice == 1) {
      data_type data = getUserInput();
      struct Node* newNode = createNode(data);
      newNode->next = head;
      head = newNode;
      printf("Node added successfully.\n");
    } else if (choice == 0) {
      break;
    } else {
      printf("Invalid choice. Please enter 1 or 0.\n");
    }
  }

  printf("Here's the linked list:\n");
  printList(head);

  // Free the allocated memory for nodes (important to avoid memory leaks)
  struct Node* current = head;
  while (current != NULL) {
    struct Node* temp = current;
    current = current->next;
    free(temp);
  }

  printf("Thank you for using the Linked List program!\n");
  return 0;
}
