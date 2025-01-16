// **Convert Binary to Decimal**: Convert a binary number represented in a doubly linked list to decimal.
// Complier command - gcc -o binary_to_decimal decimal.c -lm


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Double linked list
typedef struct Node
{
    int data;
    struct Node* prev; 
    struct Node* next;
}Node;

// create a node 
Node* createNode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the end
Node* insertatend(Node* head, int data)
{
    Node* newnode = createNode(data);
    if(head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node 
    }

    temp->next = newnode; // Link new node to current head;
    newnode->prev = temp; // Link current head back to new node
    return head; // newnode is the new head
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int binarytodecimal(Node* head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return 0;
    }

    // Traverse to the end of the linked list to determine the Least significant binarytodecimal
    Node* tail = head;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    int decimal = 0;
    int position = 0;

    // Traverse the list from tail to head (right to left in binary represpentation)
    while(tail != NULL)
    {
        if (tail->data == 1)
        {
            decimal += pow(2, position); // Add the power of 2 for each binary digit
        }
        position++;
        tail = tail->prev; // Move to the previous node
    }
    return decimal;
}

int main() {
    Node* head = NULL;

    // Create a binary number in the doubly linked list (e.g., 1011)
    head = insertatend(head, 1);
    head = insertatend(head, 0);
    head = insertatend(head, 1);
    head = insertatend(head, 1);

    printf("Binary number represented as a doubly linked list: ");
    printList(head);

    // Convert binary to decimal
    int decimalValue = binarytodecimal(head);
    printf("Decimal value: %d\n", decimalValue);

    return 0;
}