#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *queue;
    int front, rear, size, capacity;
} Queue;

Queue *create_queue(int capacity)
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->queue = (int *)malloc(sizeof(int) * capacity);
    q->front = q->size = 0;
    q->rear = -1;
    return q;
}

int is_full(Queue *q)
{
    return q->size == q->capacity;
}

int is_empty(Queue *q)
{
    return q->size == 0;
}

void enqueue(Queue *q, int item)
{
    if (is_full(q))
    {
        q->front = (q->front + 1) % q->capacity;
        q->rear = (q->rear + 1) % q->capacity;
        q->queue[q->rear] = item;
    }
    else
    {
        q->rear = (q->rear + 1) % q->capacity;
        q->queue[q->rear] = item;
        q->size++;
    }
}

int dequeue(Queue *q)
{
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->queue[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return item;
    }
}

int main()
{
    Queue *q = create_queue(5);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    printf("Dequeued item: %d\n", dequeue(q));
    return 0;
}
