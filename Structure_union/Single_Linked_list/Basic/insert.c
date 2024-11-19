// Insert at Beginning**: Function to insert a new node at the beginning.

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

void insertAtbeginning(struct node** head, int newData)
{
    // Create a new node 
    struct node* newnode = createNode(newData);

    // Make the new node next pointer point to the current head
    newnode->next = *head;

    // Update the head to point to the new node
    *head = newnode;
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
    
    //Insert nodes at the beginning of the list
    insertAtbeginning(&head, 10);
    insertAtbeginning(&head, 20);
    insertAtbeginning(&head, 30);
    
    printf("Inserting in the beginning linked list: ");
    printlist(head);

    // Free the memory allocation for the linked list
    freeList(head);
}

