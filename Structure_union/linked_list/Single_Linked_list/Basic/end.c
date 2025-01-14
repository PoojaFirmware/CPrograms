// Insert at End**: Function to insert a new node at the end.

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

void insertAtend(struct node** head, int newData)
{
    // Create a new node 
    struct node* newnode = createNode(newData);

    // If the linked list is empty, make the new node the head.
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    // Traverse to the last node
    struct node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // Link the node to the new node
    temp->next = newnode;
}

void printlist(struct node* head)
{
    //struct node* current = head;
    while (head != NULL)
    {
        printf("%d -->", head->data);
        head = head->next;
    }
    printf("NULL\n");
};

void freeList(struct node* head)
{
    struct node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp); //Free the memory allocation for the current node 
    }
    
    
}

int main()
{
    struct node* head = NULL; // Initalize an empty linked list
    
    //Insert nodes at the end of the list
    insertAtend(&head, 10);
    insertAtend(&head, 20);
    insertAtend(&head, 30);
    
    printf("Linked list after insertions at the end:\n");
    printlist(head);

    // Free the memory allocation for the linked list
    freeList(head);
}

