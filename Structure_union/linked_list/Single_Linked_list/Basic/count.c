// Count Nodes**: Function to count the nodes in the list.

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

// Counting the number of nodes in the Linked list
int countnodes(struct node* head)
{
    int count = 0;
    struct node* current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
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

    printf("Number of nodes: %d\n", countnodes(head));
    //printlist(head);

    free(head);
    free(second);
    free(third);
}


