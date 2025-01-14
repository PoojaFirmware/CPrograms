// Find the nth node from the end.
// Approach 1: Two Pointer Method (Efficient)
// Step 1: Use two pointers, first and second.
// Step 2: Move the first pointer n steps ahead.
// Step 3: Now move both first and second pointers together, one node at a time.
// Step 4: When the first pointer reaches the end, the second pointer will be at the nth node from the end.

#include <stdio.h>
#include <stdlib.h>

// The structure for linked list for node
struct node
{
    int data;            // Store data of the node
    struct node* next;   // Pointer to the next node in the list
};

// Create a new node with given data
struct node* createnode(int data)
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

void findNthfromend(struct node* head, int n)
{
    struct node* first = head;
    struct node* second = head;

    // Move the first pointer n steps ahead
    for(int i = 0; i < n; i++)
    {
        if(first == NULL)
        {
            printf("The list is shorter than %d nodes\n", n);
            return; // List is shorter than newnode
        }
        first = first->next;
    }

    // Move both first and second pointers one step at a time
    while(first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    //Now second points to the nth node from the end
    printf("The %dth node from the end is: %d\n", n, second->data);
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
    // Create a sorted linked list with duplicates: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    printf("Original List: ");
    printlist(head);

    int n = 2;
    findNthfromend(head, n); // Find the 2nd node from the end
    
    return 0;

}