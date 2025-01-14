// **Find Middle Node**: Find the middle node in one traversal.
// In the context of linked lists, finding the "middle node" typically refers to locating the node that is halfway through the list.
// If the linked list has an odd number of nodes, the middle node is the one that is exactly in the center.
// If the linked list has an even number of nodes, there are two middle nodes, and often the first one is considered the "middle" for simplicity.

// **How to Find the Middle Node:**
// The standard way to find the middle node is by using the "two-pointer technique".

// 1. **Initialize Two Pointers:** Set up two pointers, often called `slow` and `fast`.
// 2. **Move Pointers at Different Speeds:** Move the `slow` pointer one node at a time, while the `fast` pointer moves two nodes at a time.
// 3. **Stop When Fast Reaches the End:** When the `fast` pointer reaches the end of the list (or the node just before the end, if the list has an even number of nodes),
//    the `slow` pointer will be at the middle node.

// **Example:**
// For a linked list like `1 -> 2 -> 3 -> 4 -> 5`, after moving the `slow` and `fast` pointers as described,
// the `slow` pointer will end up on the node with value `3`, which is the middle.

// **Why This Works:**
// Because the `fast` pointer moves twice as fast as the `slow` pointer, by the time the `fast` pointer has gone through the entire list,
// the `slow` pointer will be halfway through, pointing to the middle node.
// This technique is efficient, with a time complexity of O(n) and requires only O(1) extra space.

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
struct node* findMiddleNode(struct node* head) 
{
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    // Finding the middle node
    struct node* middle = findMiddleNode(head);
    if (middle != NULL) {
        printf("Middle Node: %d\n", middle->data);
    }

    // Free allocated memory
    struct node* current = head;
    while (current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }

    return 0;

}

