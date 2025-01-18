// **Convert to double Linked List**: Convert the circular linked list to a double linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a nodes
typedef struct Node 
{
    int data;
    struct Node* next;
    struct Node* prev;    
}Node;

// Create a new nodes
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void  convertToDoublyLinkedList(Node* head)
{
    if(!head)
    {
        return;
    }

    Node* temp = head;
    Node* prevNode = NULL;

    // Traverse the list and set up prev pointers
    do
    {
        temp->prev = prevNode; // Set the previous node
        prevNode = temp; 
        temp = temp->next;
    } while (temp != head);

    // Break the circular connection
    temp->prev = prevNode;
    prevNode->next = NULL;
}

void displayDoublyLinkedList(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        printf("<- %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    // Create a circular linked list
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head; // Circular connection

    // Convert to doubly linked list
    convertToDoublyLinkedList(head);

    // Display the resulting doubly linked list
    displayDoublyLinkedList(head);

    return 0;
}

