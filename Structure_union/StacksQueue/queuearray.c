// Implement Queue Using Arrays
// Implement a queue using an array, supporting enqueue, dequeue, `front`, and `isEmpty` operations.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum sie of the queue 

// Queue structure definition
typedef struct
{
    int items[MAX];
    int front;
    int rear;
}Queue;

// Function to initialize the queue
void initialize(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue isEmpty
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

// Function to check if the queue is full
int isfull(Queue *queue)
{
    return queue->rear == MAX - 1; 
}

// Function to add an element to the queue
void enqueue(Queue *queue, int value)
{
    if (isfull(queue))
    {
        printf("Queue overflow! cannot enqueue %d\n", value);
    }
    else 
    {
        if (queue->front == -1) //First element to enqueue
            queue->front = 0;
        queue->items[++queue->rear] = value;
        printf("Enqueue %d\n", value);
    }
}

// Function to remove an element to the queue
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue underflow! cannot dequeue\n");
        return -1;
    }
    else
    {
        int value = queue->items[queue->front];
        if (queue->front == queue->rear) // Only one element left
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            queue->front++;
        }
        return value;
    }

}

// Function to get the front element of the queue
int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty! No front element\n");
        return -1;
    }
    else
    {
        return queue->items[queue->front];
    }
}

int main()
{
    Queue queue;
    initialize(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Top element is %d\n", front(&queue));
    printf("Poppedd element is %d\n", dequeue(&queue));
    printf("Poppedd element is %d\n", dequeue(&queue));

    if (isEmpty(&queue))
    {
        printf("queue is empty\n");
    }
    else
    {
        printf("queue is not empty\n");
    }
    return 0;
}