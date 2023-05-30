#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct node
{
    // Data stores whatever is inside the node
    // '*next' points to next node in list
    int data;
    struct node *next;
} node_t;

int get_length(node_t **head);
void insert_at_beginning(node_t **head, int data);
void insert_at_end(node_t **head, int data);
void print_list(node_t **head);

// Create new node with given data value
node_t *create_node(int data)
{
    // Allocate space for new node, data = data and it will point to null
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Insert new node at the beginning of list
void insert_at_beginning(node_t **head, int data)
{
    // '**head' is pointer to pointer, 'data' is value wanted to be stored
    node_t *new_node = create_node(data);
    new_node->next = *head;
    // New 'head' of list will the newly created node
    *head = new_node;
}

void insert_at_position(node_t **head, int position, int data)
{
    int list_length = get_length(head);
    node_t *new_node = create_node(data);

    // If list is empty
    if (*head == NULL)
    {
        *head = new_node;
        printf("List is empty. New node with value '%d' assigned as head. \n", data);
        return;
    }
    else if (position > list_length)
    {
        // Data will be last element if position is too large
        insert_at_end(head, data);
        return;
    }
    else if (position == 0)
    {
        insert_at_beginning(head, data);
        return;
    }
    else
    {
        int count = 0;
        node_t *temp = *head;

        while (temp != NULL)
        {
            if (count == position - 1)
            {
                node_t *switcher = temp->next;
                temp->next = new_node;
                new_node->next = switcher;
                break;
            }
            count += 1;
            temp = temp->next;
        }
    }
}

// Insert new node at end of list
void insert_at_end(node_t **head, int data)
{
    // '**head' is pointer to pointer, 'data' is value wanted to be stored
    node_t *new_node = create_node(data);
    // If list is empty
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    // Loop until final node is reached
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Once final node is reached, change to new node
    temp->next = new_node;
}

// Get length of linked list
int get_length(node_t **head)
{
    node_t *temp = *head;
    int length = 0;
    // Iterate through the list until NULL is reached
    while (temp != NULL)
    {
        temp = temp->next;
        // Add one to length after each iteration
        length++;
    }
    return length;
}

// Define a function to print the linked list
void print_list(node_t **head)
{
    node_t *temp = *head;
    // Loop until final node is reached
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Test
int main()
{
    // Create an empty list head
    node_t *head = NULL;

    insert_at_beginning(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 40);
    insert_at_end(&head, 30);
    print_list(&head);

    // print_list(head);
    // printf("Length of list is %d\n", get_length(&head));
    // insert_at_position(&head, 4 , 34);
    insert_at_position(&head, 0, 21);
    print_list(&head);
    return 0;
}
