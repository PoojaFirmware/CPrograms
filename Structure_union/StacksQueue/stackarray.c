// Implement Stack Using Arrays
// Implement a basic stack data structure using arrays, 
// supporting standard operations like `push`, `pop`, `peek`, and `isEmpty`.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum sie of the stack 

// Stack structure definition
typedef struct
{
    int items[MAX];
    int top;
}stack;

// Function to initialize the stack
void initialize(stack *stack)
{
    stack->top = -1;
}

// Function to check if the stack isEmpty
int isEmpty(stack *stack)
{
    return stack->top == -1;
}

// Function to check if the stack is full
int isfull(stack *stack)
{
    return stack->top == MAX - 1; 
}

// Function to add an element to the stack 
void push(stack *stack, int value)
{
    if (isfull(stack))
    {
        printf("Stack overflow! cannot push %d\n", value);
    }
    else 
    {
        stack->items[++stack->top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

int pop(stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow! cannot pop\n");
    }
    else
    {
        return stack->items[stack->top--];
    }
}

int peek(stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty! cannot peek\n");
        return -1;
    }
    else
    {
        return stack->items[stack->top];
    }
}

int main()
{
    stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is %d\n", peek(&stack));
    printf("Poppedd element is %d\n", pop(&stack));
    printf("Poppedd element is %d\n", pop(&stack));

    if (isEmpty(&stack))
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
    return 0;
}

