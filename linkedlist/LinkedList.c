#include <stdio.h>
#include <stdlib.h>

typedef struct node_t
{
    int val;
    struct node_t *link;
} node_t;

void insert_at_end(node_t **head_ptr, int value)
{

    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->val = value;
    node->link = NULL;

    if (*head_ptr == NULL)
    {
        *head_ptr = node;
    }
    else
    {
        node_t *temp = *head_ptr;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = node;
    }
}

void insert_at_front(node_t **head_ptr, int value)
{

    if (*head_ptr == NULL)
    {
        printf("no elements.");
    }

    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->val = value;
    node->link = *head_ptr;
    *head_ptr = node;
}

void printnode(const node_t *const *head_ptr)
{

    if (*head_ptr == NULL)
    {
        printf("no elements in the linked list.");
    }
    else
    {
        const node_t *temp = *head_ptr;
        while (temp != NULL)
        {
            printf("%d ", temp->val);
            temp = temp->link;
        }
        printf("\n");
    }
}

void deleteatfront(node_t **head_ptr)
{

    if (*head_ptr == NULL)
    {
        printf("no elements to delete. ");
    }
    else
    {
        node_t *temp = *head_ptr;
        *head_ptr = (*head_ptr)->link;
        free(temp);
    }
}

void deleteatend(node_t **head_ptr)
{

    if (*head_ptr == NULL)
    {
        printf("no elements to delete. ");
    }
    else if ((*head_ptr)->link == NULL)
    {
        free(*head_ptr);
        *head_ptr = NULL;
    }
    else
    {
        node_t *temp = *head_ptr;

        while (temp->link->link != NULL)
        {
            temp = temp->link;
        }

        node_t *tobedeleted = temp->link;
        temp->link = NULL;
        free(tobedeleted);
    }
}

void reverse_list(node_t **head_ptr)
{

    if (*head_ptr == NULL)
    {
        printf("no elements in the list");
    }
    else
    {
        node_t *next_node = NULL;
        node_t *current_node = *head_ptr;
        node_t *previous_node = NULL;

        while (current_node != NULL)
        {
            next_node = current_node->link;
            current_node->link = previous_node;
            previous_node = current_node;       
            current_node = next_node;
        }
        *head_ptr = previous_node;
    }
}

int main()
{

    node_t *head_ptr = NULL;
   
    insert_at_end(&head_ptr, 10);
    insert_at_end(&head_ptr, 20);
    printf("initial list : ");
    printnode((const node_t *const *)&head_ptr);

    insert_at_front(&head_ptr, 0);
    printf("\nadded at front : ");
    printnode((const node_t *const *)&head_ptr);

    reverse_list(&head_ptr);
    printf("\nreversed list :");
    printnode((const node_t *const *)&head_ptr);

    deleteatfront(&head_ptr);
    printf("\ndeleted at front :");
    printnode((const node_t *const *)&head_ptr);

    deleteatend(&head_ptr);
    printf("\ndeleted at end :");
    printnode((const node_t *const *)&head_ptr);
    
    printf("done. ");
    return 0;
}