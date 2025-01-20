#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL; // Correct initialization
    return newNode;
}

// Detect a loop using Floyd’s Cycle Detection Algorithm
Node* detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps

        // If slow and fast meet, a loop exists
        if (slow == fast)
        {
            return slow;
        }
    }
    return NULL; // No loop detected
}

// Remove the loop from the linked list
void removeLoop(Node* head, Node* loopNode)
{
    Node* ptr1 = head;
    Node* ptr2 = loopNode;

    // Find the length of the loop
    int loopLength = 1;
    while (ptr2->next != loopNode)
    {
        ptr2 = ptr2->next;
        loopLength++;
    }

    // Move one pointer ahead by the loop length
    ptr1 = head;
    ptr2 = head;
    for (int i = 0; i < loopLength; i++)
    {
        ptr2 = ptr2->next;
    }

    // Move both pointers until they meet at the start of the loop
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // Find the last node in the loop and break it
    ptr2 = ptr1;
    while (ptr2->next != ptr1)
    {
        ptr2 = ptr2->next;
    }
    ptr2->next = NULL;

    printf("Loop removed\n");
}

// Create a loop in the linked list for testing
void createLoop(Node* head, int k)
{
    Node* temp = head;
    Node* loopStart = NULL;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == k)
        {
            loopStart = temp;
        }
        temp = temp->next;
        count++;
    }

    // Create the loop
    temp->next = loopStart;
}

// Print the linked list
void printList(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Create a loop for testing
    createLoop(head, 3);

    // Detect the loop
    Node* loopNode = detectLoop(head);

    if (loopNode)
    {
        printf("Loop detected.\n");
        // Remove the loop
        removeLoop(head, loopNode);
    }
    else
    {
        printf("No loop detected.\n");
    }

    // Print the list after removing the loop
    printList(head);

    return 0;
}
