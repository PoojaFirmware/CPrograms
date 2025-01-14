// Merge two sorted linked lists 
// Another way to question - Sort in O(n log n): Sort the linked list using an efficient algorithm.

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

struct node* mergesorted(struct node* l1, struct node* l2)
{
    // If one of the lists is empty return the other
    if(l1 == NULL)
    {
        return l2;
    }

    if(l2 == NULL)
    {
        return l1;
    }

    struct node dummy;
    struct node* tail = &dummy; // Pointer to the last node of of the merged List
    dummy.next = NULL;

    // traverse both list
    while (l1 != NULL && l2 != NULL)
    {
        if(l1->data <= l2->data)
        {
            tail->next = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // MOve the tail pointer
    }
    // Attach the remaining nodes from either list
    if (l1 != NULL)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }
    return dummy.next; // Return the merged list starting from the first real node
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
    // Create the first sorted linked list: 1 -> 3 -> 5 -> NULL
    struct node* l1 = createnode(1);
    l1->next = createnode(3);
    l1->next->next = createnode(5);

    // Create the second sorted linked list: 2 -> 4 -> 6 -> NULL
    struct node* l2 = createnode(2);
    l2->next = createnode(4);
    l2->next->next = createnode(6);

    printf("List 1: \n");
    printlist(l1);

    printf("List 2: \n");
    printlist(l2);

    // Merge the two and sorted lists
    struct node* mergelist = mergesorted(l1, l2);

    printf("Merge list: \n");
    printlist(mergelist);


}