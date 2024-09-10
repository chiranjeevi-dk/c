//linkedlist

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node{
    int val;
    struct node *link; 
}node_t;

typedef struct llist{
    node_t *head;
}llist_t;

llist_t *create_llist();
node_t *create_node(int value);
void insert_at_end(node_t **head_ptr, int value);
void insert_at_front(node_t **head_ptr, int value);
void print_list(node_t *head_ptr);
void delete_at_front(node_t **head_ptr);
void delete_at_end(node_t **head_ptr);
void reverse_list(node_t **head_ptr);
void delete_entire_list(llist_t *list);

#endif