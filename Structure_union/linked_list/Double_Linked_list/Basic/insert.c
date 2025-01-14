// **Insert at Beginning**: Insert a new node at the beginning.
// **Insert at End**: Insert a new node at the end.

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
    Node* head = NULL;

    // Insert nodes at the beginning
    head = insertatBeginning(head, 10);
    head = insertatBeginning(head, 20);
    head = insertatBeginning(head, 30);

    // Display the list after inserting at the beginning
    displaylist(head); // Expected: 30 20 10

    // Insert nodes at the end
    head = insertatend(head, 40);
    head = insertatend(head, 50);

    // Display the list after inserting at the end
    displaylist(head); // Expected: 30 20 10 40 50

    return 0;
}




