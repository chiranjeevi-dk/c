#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *link;
} node_t;

typedef struct llist {
    node_t *head;
} llist_t;


llist_t *create_llist() {
    llist_t *linkedlist = (llist_t *)malloc(sizeof(llist_t));
    
    if (linkedlist == NULL) {
        perror("Memory was not allocated.");
        return NULL;
    }

    linkedlist->head = NULL;
    return linkedlist;
}

node_t *create_node(int value){

    node_t *new_node = (node_t *)malloc(sizeof(node_t));

    if(new_node == NULL){
        fprintf(stderr, "Node not created in function: %s\n", __func__);
        return NULL;
    }
    new_node->val = value;
    new_node->link = NULL;
    
    return new_node;
}

void insert_at_end(node_t **head_ptr, int value) {
    
    node_t *node = create_node(value);
    if(node == NULL){
        fprintf(stderr, "Node not created in function: %s\n", __func__);
        return; 
    }

    if (*head_ptr == NULL) {
        *head_ptr = node;
    } else {
        node_t *temp = *head_ptr;
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = node;
    }

}

void insert_at_front(node_t **head_ptr, int value) {
  
    node_t *node = create_node(value);
    if(node == NULL){
        fprintf(stderr, "Node not created in function: %s\n", __func__);
        return; 
    }

    node->link = *head_ptr;
    *head_ptr = node;

}

void print_list( node_t *head_ptr) {

    if (head_ptr == NULL) {
        printf("no elements in the linked list.\n");
    } else {
        node_t *temp = head_ptr;
        while (temp != NULL) {
            printf("%d -> ", temp->val);
            temp = temp->link;
        }
        printf("NULL\n\n");
    }

}

void delete_at_front(node_t **head_ptr) {
    if (*head_ptr == NULL) {
        printf("no elements to delete.\n");
    } else {
        node_t *temp = *head_ptr;
        *head_ptr = (*head_ptr)->link;
        free(temp);
    }
}

void delete_at_end(node_t **head_ptr) {
    if (*head_ptr == NULL) {
        printf("no elements to delete.\n");
    } else if ((*head_ptr)->link == NULL) {
        free(*head_ptr);
        *head_ptr = NULL;
    } else {
        node_t *temp = *head_ptr;
        while (temp->link->link != NULL) {
            temp = temp->link;
        }
        node_t *tobedeleted = temp->link;
        temp->link = NULL;
        free(tobedeleted);
    }
}

void reverse_list(node_t **head_ptr) {
    if (*head_ptr == NULL) {
        printf("no elements in the list\n");
    } else {
        node_t *next_node = NULL;
        node_t *current_node = *head_ptr;
        node_t *previous_node = NULL;

        while (current_node != NULL) {
            next_node = current_node->link;
            current_node->link = previous_node;
            previous_node = current_node;       
            current_node = next_node;
        }
        *head_ptr = previous_node;
    }
}

void delete_entire_list(llist_t *list){

    if(list == NULL){
        perror("List is empty.");
        return;
    }

    while(list->head != NULL){
        delete_at_front(&list->head);
    }

    free(list);
}


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
