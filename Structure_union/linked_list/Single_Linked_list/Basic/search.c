// Search in Linked List**: Search for a specific value and return its position.

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

int searchIn(struct node* head, int target)
{
    int position = 1;
    struct node* current = head;

    while (current != NULL)
    {
        if (current->data == target)
        {
            return position; // Return the position if the target is found
        }
        current = current->next;
        position++;
    }
    return -1; // Return -1 the position if the target is not found
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

int main()
{
    struct node* head = createNode(10);
    struct node* second = createNode(20);
    struct node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    int target = 2;
    int result = searchIn(head, target);

    if (result != -1) 
    {
        printf("Value %d found at position %d\n", target, result);
    } 
    else 
    {
        printf("Value %d not found in the list\n", target);
    }

    free(head);
    free(second);
    free(third);
}


