#include <stdio.h>
#include "linkedlist.h"

int main() {
    llist_t *list = create_llist();
    int choice = 1;
    int option, value;

    while (choice) {
        printf("Choose an option:\n");
        printf("1) Insert at end\n");
        printf("2) Insert at front\n");
        printf("3) Print the list\n");
        printf("4) Reverse the list\n");
        printf("5) Delete at front\n");
        printf("6) Delete at end\n");
        printf("7) Delete entire list\n");
        printf("Enter the option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the value to insert at end: ");
                scanf("%d", &value);
                insert_at_end(&list->head, value);
                printf("Inserted at end.\n");
                break;
            case 2:
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insert_at_front(&list->head, value);
                printf("Inserted at front.\n");
                break;
            case 3:
                printf("The list: ");
                print_list(list->head);
                break;
            case 4:
                reverse_list(&list->head);
                printf("List reversed.\n");
                break;
            case 5:
                delete_at_front(&list->head);
                printf("Deleted at front.\n");
                break;
            case 6:
                delete_at_end(&list->head);
                printf("Deleted at end.\n");
                break;
            case 7:
                delete_entire_list(list);
                printf("List deleted.\n");
                break;
            default:
                fprintf(stderr, "Invalid option. Please try again.\n");
                break;
        }

        printf("\nEnter 1 to continue or 0 to exit: ");
        scanf("%d", &choice);
        printf("\n");
    }

    return 0;
}
