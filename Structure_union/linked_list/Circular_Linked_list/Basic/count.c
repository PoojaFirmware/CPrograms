// **Count Nodes**: Count the number of nodes.

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

int countNode(struct Node* head)
{
    // Step1: Check if the list is empty
    if (head == NULL)
    {
        return 0; // No nodes in the list
    }

    int count = 1; // Count the head node
    struct Node* temp = head;

    // Step2: Traverse the list until we loop back to the head
    while(temp->next != head)
    {
        count++;
        temp  = temp->next; 
    }
    return count;
}

void insertatend(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        *head = newNode; // Update the head
        return; 
    }

    // Find the last node
    struct Node* temp = *head;
    while(temp->next != *head)
    {
        temp = temp->next; // Traverse to the last node
    }

    // Update pointers for the circular structure
    temp->next = newNode;
    newNode->next = *head;
}

// To display the circular linked list
void displayList(struct Node* head)
{
    if(!head)
    {
        printf(" The list is empty\n");
        return;
    }

    struct Node* temp = head;
    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head: %d)\n", head->data);    
}

int main() {
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 40);

    // Display the list
    printf("Circular Linked List: ");
    displayList(head);

    // Count the nodes in the list
    int totalNodes = countNode(head);
    printf("Total number of nodes: %d\n", totalNodes);

    return 0;
}