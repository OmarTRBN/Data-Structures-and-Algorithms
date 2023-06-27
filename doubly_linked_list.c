#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
    // Data stores whatever is inside the node
    // '*next' points to next node in list
    int data;
    struct node_struct *next;
    struct node_struct *previous;
} Node;

Node *create_node(int data);
int get_length(Node **head);
void insert_at_beginning(Node **head, Node **last, int data);
void insert_at_end(Node **head, Node **last, int data);
void print_list_forward(Node **head);
void print_list_backward(Node **last);

int main()
{
    Node *head = NULL;
    Node *last = NULL;

    insert_at_beginning(&head, &last, 10);
    insert_at_beginning(&head, &last, 20);
    insert_at_beginning(&head, &last, 50);
    insert_at_end(&head, &last, 20);

    // printf("%d | ", head->previous->data);
    printf("%d | ", head->data);
    printf("%d\n", head->next->previous->data);
    printf("%d\n", get_length(&head));
    print_list_forward(&head);
    printf("\n");
    print_list_backward(&last);
    return 0;
}

Node *create_node(int data)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->previous = NULL;
    return new_node;
}

int get_length(Node **head) 
{
    Node *temp = *head;
    int count = 0;
    while (temp != NULL)
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}

void insert_at_beginning(Node **head, Node **last, int data)
{
    Node *new_node = create_node(data);
    /* If *head == NULL, setting previous
     will cause seg fault */
    if (*head == NULL)
    {
        *head = new_node;
        *last = new_node;
    }
    else
    {
        new_node->next = *head;
        (*head)->previous = new_node;
        *head = new_node;
    }
    // The order is very important!
    return;
}

void insert_at_end(Node **head, Node **last, int data)
{
    Node *new_node = create_node(data);
    // If *head ==  NULL then list is empty
    if (*head != NULL)
    {
        new_node->previous = *last;
        (*last)->next = new_node;
        *last = new_node;
    }
    else
    {
        *head = new_node;
        *last = new_node;
    }
    return;
}

void print_list_forward(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        printf("%d | ", temp->data);
        temp = temp->next;
    }
    return;
}

void print_list_backward(Node **last)
{
    Node *temp = *last;
    while (temp != NULL)
    {
        printf("%d | ", temp->data);
        temp = temp->previous;
    }
}
