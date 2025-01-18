// **Insert in an empty List**: Insertion in an empty List in the circular linked list.
// **Insert at Beginning**: Insert a node at the beginning. 
// **Insert at End**: Insert a node at the end.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

// Create a new nodes
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEmpty(struct Node* head, int data)
{
    if(head != NULL)
    {
        return head; // List is not empty
    }

    struct Node* newNode = createNode(data);
    newNode->next = newNode; // Point to itself
    return newNode; // New node becomes the head;
}

// Steps for Insertion at the Beginning in a Circular Linked List

// 1. Create a New Node:
// Allocate memory for the new node and assign the desired value to it.

// 2. Check if the List is Empty:
// If the list is empty:
// - Point the new node's next to itself.
// - Make the new node the head of the list.
// - Exit.

// 3. Traverse to the Last Node:
// Start from the head and move to the node where next points back to the head.

// 4. Update Pointers:
// - Set the next of the new node to the current head.
// - Update the next of the last node to point to the new node.

// 5. Make the New Node the Head:
// Update the head pointer to the new node.

struct Node* insertatbeginning(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        return newNode; // New node is now the head
    }

    // Find the last node
    struct Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next; // Traverse to the last node
    }

    // Update pointers for the circular structure
    temp->next = newNode;
    newNode->next = head;
    return newNode; // return the new head
}

// Steps for Insertion at the End in a Circular Linked List

// 1. Create a New Node:
// Allocate memory for the new node and assign the desired value to it.

// 2. Check if the List is Empty:
// If the list is empty:
// - Point the new node's next to itself.
// - Make the new node the head of the list.
// - Exit.

// 3. Traverse to the Last Node:
// Start from the head and move to the node where next points back to the head.

// 4. Update Pointers:
// - Set the next of the last node to the new node.
// - Set the next of the new node to the head.

// 5. Keep the Head Unchanged:
// The head pointer remains unchanged.

struct Node* insertatend(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);
    if (head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        return newNode; // New node is now the head
    }

    // Find the last node
    struct Node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next; // Traverse to the last node
    }

    // Update pointers for the circular structure
    temp->next = newNode;
    newNode->next = head;
    return head; // return the existing head
}

// Difference in insert at the beginning and insert at the end is return new head and here return existing head

// Steps for Insertion at Specific Position in a Circular Linked List

// 1. Create a New Node:
// - Allocate memory for the new node and assign the desired value to it.

// 2. Check if the List is Empty:
// - If the list is empty:
//     - Point the new node's next to itself.
//     - Make the new node the head of the list.
//     - Return the new node as the head.

// 3. If Insertion Position is 1 (Insert at the Beginning):
// - Traverse to the last node of the list (where next points to the head).
// - Update the last node's next to the new node.
// - Set the new node's next to the head.
// - Return the new node as the head.

// 4. Traverse to the Desired Position:
// - Start from the head and move through the list until you reach the node just before the specified position.
// - If the position is beyond the list length, treat it as insertion at the end (similar to insert at the end).

// 5. Update Pointers:
// - Set the new node's next pointer to the node at the specified position.
// - Update the previous node’s next pointer to point to the new node.

// 6. Return the head:
// - Return the head pointer (unchanged) after insertion.

struct Node* insertatspecificedposition(struct Node* head, int data, int position)
{
    struct Node* newNode = createNode(data);

    // Check if the list is empty
    if (head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        return newNode; // New node is now the head
    }

    // If position is 1, insert at the begining (same as insertatbeginning)
    if (position == 1)
    {
        struct Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next; // Traverse to the last node
        }

        // Update pointers for the circular structure
        temp->next = newNode;
        newNode->next = head;
        return newNode; // return the new head
    }

    // Traverse to the position just before the specified position
    struct Node* temp = head;
    int count = 1;
    while (count < position - 1 && temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    
    // Insert the new node at the specified position 
    newNode->next = temp->next;
    temp->next = newNode;

    return head; // Return the head(unchanged)
}

// To display the circular linked list
void displayList(struct Node* head)
{
    if(!head)
    {
        printf(" The list is empty\n");
        return;
    }

    struct Node* temp = head;
    do
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head: %d)\n", head->data);    
}

int main()
{
    struct Node* head = NULL;

    // Insertion in an empty list
    head = insertEmpty(head, 10);
    printf("After insertion into an empty list:\n");
    displayList(head);

    // Insertion at the beginning
    head = insertatbeginning(head, 5);
    printf("After insertion at the beginning:\n");
    displayList(head);

    // Insertion at the end
    head = insertatend(head, 20);
    printf("After insertion at the end:\n");
    displayList(head);

    // Insertion at a given position
    head = insertatspecificedposition(head, 15, 3);
    printf("After insertion at position 3:\n");
    displayList(head);

    return 0;
}













