// Remove duplicate nodes from a sorted list
// To remove duplicate nodes from a sorted singly linked list in C, you can traverse the list and compare each node with its next node. 
// If two consecutive nodes have the same value, remove the duplicate by adjusting the next pointer.

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

// Function to find the middle node in one traversal
struct node* removeDuplicates(struct node* head) 
{
    struct node* current = head;

    while (current != NULL && current->next != NULL) 
    {
        if(current->data == current->next->data)
        {
            // Duplicate found; remove it.
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            // Move to the next distinct element
            current = current->next;
        }
    }
}

void printlist(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%d -->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a sorted linked list with duplicates: 1 -> 1 -> 2 -> 3 -> 3 -> NULL
    struct node* head = createNode(1);
    head->next = createNode(1);
    head->next->next = createNode(2);
    head->next->next->next = createNode(3);
    head->next->next->next->next = createNode(3);

    printf("Original List: ");
    printlist(head);

    removeDuplicates(head);

    printf("List after removing duplicates:\n");
    printlist(head);
    
    return 0;

}

