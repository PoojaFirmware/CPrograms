// **Count Nodes**: Count the number of nodes.

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

int countnodes(Node* head)
{
    int count = 0;
    Node* temp = head;

    // Traverse the linked list
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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
    // Create nodes manually and link them
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);

    // Link the nodes manually
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;

    // Count and display the number of nodes in the list
    int nodeCount = countnodes(head);
    printf("Total number of nodes in the list: %d\n", nodeCount);
}