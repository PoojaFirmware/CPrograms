// **Search Node**: Search for a value and return its position.

#include <stdio.h>
#include <stdlib.h>

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

// Insert at the beginning 
Node* insertatBeginning(Node* head, int data)
{
    Node* newnode = createNode(data);
    if(head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }
    newnode->next = head; // Link new node to current head;
    head->prev = newnode; // Link current head back to new node
    return newnode; // newnode is the new head
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

int searchnode(Node* head, int value)
{
    Node* temp = head;
    int position = 1; // Position starts from 1(not 0)

    while (temp != NULL)
    {
        if(temp->data == value)
        {
            return position; // Return position if value is found
        }
        temp = temp->next;
        position++;
    }
    return -1; // Return -1 if the value is not found
}

int main() 
{
    Node* head = NULL;

    // Inserting nodes at the beginning
    head = insertatBeginning(head, 10);
    head = insertatBeginning(head, 20);
    head = insertatBeginning(head, 30);
    head = insertatBeginning(head, 40);
    head = insertatBeginning(head, 50);

    printf("Original list:\n");
    displaylist(head);

    // Searching for a value
    int value = 30;
    int position = searchnode(head, value);
    if (position != -1) 
    {
        printf("Node with value %d found at position %d.\n", value, position);
    } 
    else 
    {
        printf("Node with value %d not found.\n", value);
    }

    value = 100;
    position = searchnode(head, value);
    if (position != -1) 
    {
        printf("Node with value %d found at position %d.\n", value, position);
    } 
    else 
    {
        printf("Node with value %d not found.\n", value);
    }

    return 0;
}