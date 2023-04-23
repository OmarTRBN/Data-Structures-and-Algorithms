#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct
{
    int arr[MAX_SIZE];
    int top;
} Stack;

void init_stack(Stack *s)
{
    s->top = -1;
}

int is_empty(Stack *s)
{
    return s->top == -1;
}

int is_full(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int item)
{
    if (is_full(s))
    {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = item;
}

int pop(Stack *s)
{
    if (is_empty(s))
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int main()
{
    Stack s;
    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("Popped item: %d\n", pop(&s));
    printf("Popped item: %d\n", pop(&s));
    printf("Popped item: %d\n", pop(&s));
    printf("Popped item: %d\n", pop(&s));
    return 0;
}
