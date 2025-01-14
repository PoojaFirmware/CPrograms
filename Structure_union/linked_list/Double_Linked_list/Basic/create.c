// **Create a Doubly Linked List**: Define a node structure with `prev` and `next` pointers, and create a basic list.

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

void displaylist(Node* head)
{
    Node* temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    // Create nodes
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(60);

    // Link the node
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    displaylist(head);
}




