#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the linked list
typedef struct node
{
    int data;
    struct node *next;
} node_t;

// Define a function to create a new node with a given data value
node_t *create_node(int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Define a function to insert a new node at the beginning of the list
void insert_at_beginning(node_t **head, int data)
{
    node_t *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;
}

// Define a function to insert a new node at the end of the list
void insert_at_end(node_t **head, int data)
{
    node_t *new_node = create_node(data);
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Define a function to print the linked list
void print_list(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Define a main function to test the linked list
int main()
{
    node_t *head = NULL;
    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    print_list(head);
    return 0;
}
