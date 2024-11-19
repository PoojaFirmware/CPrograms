// Reverse Linked List: Reverse the linked list.

#include <stdio.h>
#include <stdlib.h>

// The structure for linked list for Node
struct node
{
    int data;            // Store data of the node
    struct node* next;   // Pointer to the next node in the list
};

// Create a new node with given data
struct node* createNode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exits the program if memory allocation fails
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Printing the Linked List
void printlist(struct node* head)
{
    //struct node* current = head;
    while (head != NULL)
    {
        printf("%d -->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct node* reverseList (struct node* head)
{
    struct node* prev = NULL; // Initalise previous pointer as NULL;
    struct node* current = head; // Start with the head node
    struct node* next = NULL; // Temporary pointer to store next node

    while (current != NULL)
    {
        next = current->next;       // Store next node
        current->next = prev;       // Reverse the current node's pointer
        prev = current;             // Move prev one step forward
        current = next;             // Move current one step forward
    }
    head = prev; // Update head to the new front of the list
    return head; 
}

int main()
{
    struct node* head = createNode(10);
    struct node* second = createNode(20);
    struct node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Original List:\n");
    printlist(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    printlist(head);

    // free(head);
    // free(second);
    // free(third);
}


