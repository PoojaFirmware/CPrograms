#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int detectcycle(struct Node* head)
{
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // MOve fast pointer two steps

        if (slow == fast)
        {
            return 1; // Cycle detected
        }
    }
    return 0; // No cycle
}

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main()
{
    // Create a linked list with a cycle 
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    // Last node points to NULL no cycle detected.
    // Create a cycle
    // head->next->next->next->next = head->next; 

    if (detectcycle(head))
    {
        printf("Cycle detected\n");
    }
    else
    {
        printf("No Cycle detected\n");
    }
}