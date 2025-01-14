// Split the list into two halves.
// To split a linked list into two halves in C, you can use the slow and fast pointer technique. The idea is to use two pointers: one moving slowly and the other moving quickly. When the fast pointer reaches the end, the slow pointer will be at the middle, which can be used to split the list.

// Steps:
// Use two pointers: The slow pointer moves one step at a time, and the fast pointer moves two steps at a time.
// Find the middle: When the fast pointer reaches the end of the list, the slow pointer will be at the middle.
// Split the list: Once the middle is found, break the list into two parts at that point.

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

struct node* splithalves(struct node* head, struct node** firsthalf, struct node** secondhalf) 
{
    // If the list is empty or only one element, return 
    if (head == NULL || head->next == NULL)
    {
        *firsthalf = head;
        *secondhalf = NULL;
        return NULL;
    }
    struct node* slow = head;
    struct node* fast = head;

    // Move slow to the middle, fast to the end
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into halves
    *firsthalf = head;
    *secondhalf = slow->next;
    slow->next = NULL; // Terminate the first half
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

int main()
{
    // Creating a sample linked list 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Original List: ");
    printlist(head);

    struct node* firsthalf = NULL;
    struct node* secondhalf = NULL;

    // Split the list into two halves
    splithalves(head, &firsthalf, &secondhalf);

    printf("First Half: \n");
    printlist(firsthalf);

    printf("Second Half: \n");
    printlist(secondhalf);

}


