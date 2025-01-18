// **Convert to Singly Linked List**: Convert the circular linked list to a singly linked list.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a nodes
struct Node 
{
    int data;
    struct Node* next;
};

// Create a new nodes
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// To display the circular linked list
void displayList(struct Node* head) 
{
    struct Node* temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void convertTosingleLinkedList(struct Node* head)
{
    if (!head)
    {
        return;
    }

    struct Node* temp = head;

    // Traverse the list to find the last node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    // Break the circular connection
    temp->next = NULL;
}

int main()
{
    // Create a circular linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = head; // Circular connection

    // Convert to singly linked list
    convertTosingleLinkedList(head);

    // Display the resulting singly linked list
    displayList(head);

    return 0;
}