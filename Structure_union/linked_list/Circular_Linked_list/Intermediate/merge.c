// **Merge Two Circular Lists**: Merge two sorted circular linked lists.


#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node 
typedef struct Node
{
    int data;
    struct Node* next;
}Node;

// Create a new node 
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Pointing to itself for circular motion
    return newNode;
}

// Steps for Sorted Insert
// Handle Empty List:

// If the list is empty (head == NULL), the new node becomes the only node.
// Make its next pointer point to itself to maintain the circular nature.
// Insert Before Head:

// If the new node's value is smaller than the head's value, insert it before the head.
// Traverse to the last node (where last->next == head).
// Update the last node's next pointer to point to the new node.
// Update the head to the new node.
// Insert in the Middle or End:

// Traverse the list to find the correct position where the new node's value fits between two existing nodes.
// Update the next pointers to insert the new node.

Node* sortedInsert(Node* head, int data)
{
    Node* newNode = createNode(data);

    // Case1: Empty list
    if (!head)
    {
        return newNode; // The node points to itself
    }

    Node* current = head, *prev = NULL;

    // Case 2: Insert before the head
    if (data < head->data)
    {
        // Find the last node
        Node* last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
        return newNode; // New node becomes the head
    } 

    // Case 3: Insert in the Middle or end
    do
    {
        prev = current;
        current = current->next;

        if(data >= prev->data && data <= current->data)
        {
            break;
        }
    } while (current != head);

    newNode->next = current;
    prev->next = newNode;
    return head; // head remains unchanged
}

// Steps for Merge Function
// Break the Circular Nature:

// For each list, find the last node (last->next == head).
// Temporarily make the next pointer of the last node NULL to treat the lists as regular linked lists.
// Use Two Pointers to Merge:

// Initialize two pointers, ptr1 for the first list and ptr2 for the second list.
// Compare the data values at ptr1 and ptr2:
// Add the smaller value to the merged list using the sortedInsert function.
// Move the pointer for the list from which the smaller value was taken.
// Handle Remaining Nodes:

// If one list is exhausted but the other still has nodes, add all remaining nodes from the non-empty list to the merged list.
// Restore Circular Nature:

// After merging, traverse to the last node of the merged list.
// Make the next pointer of the last node point back to the head of the merged list.

Node* mergeCircularLists(Node* head1, Node* head2)
{
    // If one of the lists is empty, return the other list
    if (!head1) return head2;
    if (!head2) return head1;

    // Find the last node of each list and break the circular nature
    Node* last1 = head1;
    while (last1->next != head1) last1 = last1->next;
    last1->next = NULL;

    Node* last2 = head2;
    while (last2->next != head2) last2 = last2->next;
    last2->next = NULL;

    // Merge two sorted lists
    Node* mergedHead = NULL;
    Node* tail = NULL;

    Node* ptr1 = head1;
    Node* ptr2 = head2;

    while (ptr1 && ptr2)
    {
        Node* minNode = NULL;
        if (ptr1->data <= ptr2->data)
        {
            minNode = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            minNode = ptr2;
            ptr2 = ptr2->next;
        }

        if (!mergedHead)
        {
            mergedHead = minNode;
            tail = minNode;
        }
        else
        {
            tail->next = minNode;
            tail = minNode;
        }
    }

    // Add remaining nodes from either list
    tail->next = (ptr1) ? ptr1 : ptr2;

    // Find the last node in the merged list
    while (tail->next) tail = tail->next;

    // Restore circular nature
    tail->next = mergedHead;

    return mergedHead;
}

void printCircularList(Node* head) 
{
    if (!head) 
    {
        return;
    }

    Node* temp = head;
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() 
{
    Node* head1 = NULL;
    Node* head2 = NULL;

    // Create first circular linked list
    head1 = sortedInsert(head1, 10);
    head1 = sortedInsert(head1, 20);
    head1 = sortedInsert(head1, 30);

    // Create second circular linked list
    head2 = sortedInsert(head2, 15);
    head2 = sortedInsert(head2, 25);
    head2 = sortedInsert(head2, 35);

    printf("List 1: ");
    printCircularList(head1);

    printf("List 2: ");
    printCircularList(head2);

    // Merge the two lists
    Node* mergedHead = mergeCircularLists(head1, head2);

    printf("Merged List: ");
    printCircularList(mergedHead);

    return 0;
}










