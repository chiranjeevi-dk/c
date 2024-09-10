#include <stdio.h>
#include "linkedlist.h"

int main() {
    llist_t *list = create_llist();
    
    insert_at_end(&list->head, 10);
    insert_at_end(&list->head, 20);
    printf("Initial list: ");
    print_list(list->head);

    insert_at_front(&list->head, 0);
    printf("Added at front: ");
    print_list(list->head);

    reverse_list(&list->head);
    printf("Reversed list: ");
    print_list(list->head);

    delete_at_front(&list->head);
    printf("Deleted at front: ");
    print_list(list->head);

    delete_at_end(&list->head);
    printf("Deleted at end: ");
    print_list(list->head);

    delete_entire_list(list);
    printf("List has been deleted\n");

    return 0;
}
