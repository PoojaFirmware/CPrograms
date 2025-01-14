// **Display List Forward and Backward**: Display nodes in both directions.

#include <stdio.h>
#include <stdlib.h>

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

// Display the list in forward direction
void displaylistforward(Node* head)
{
    Node* temp = head;
    printf("Doubly Linked List(forward): ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Display the list in backward direction
void displaylistbackward(Node* head)
{
    if(head == NULL)
    {
        printf("Doubly linked list(backward): List is empty");
        return;
    }

    Node* temp = head; // Traverse bacward from the last node
    while(temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node 
    }

    printf("Doubly Linked List(backward): ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    // Insert nodes at the end of the list
    head = insertatend(head, 10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 40);

    // Display the list in forward and backward directions
    displaylistforward(head);  // Expected: 10 20 30 40
    displaylistbackward(head); // Expected: 40 30 20 10
}