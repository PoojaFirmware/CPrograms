// **Create Circular Linked List**: Define a circular linked list and create a simple list with a few nodes.
// **Display List**: Display all elements in the circular list. 

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

// Create a circular linked list
struct Node* createcircularlist(int data[], int size)
{
    if (size == 0)
    {
        return NULL;
    }

    struct Node* head = createNode(data[0]);
    struct Node* temp = head;

    // Create the rest of the list
    for (int i = 1; i <size; i++)
    {
        temp->next = createNode(data[i]);
        temp = temp->next;
    }
    temp->next = head; // Link the last node back to the head to make it circular
    return head;
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

int main()
{
    int data[] = {10, 20, 30, 40};
    int size = sizeof(data)/sizeof(data[0]);

    struct Node* circularList = createcircularlist(data, size);
    printf("circular linked list: \n");
    displayList(circularList);
}

