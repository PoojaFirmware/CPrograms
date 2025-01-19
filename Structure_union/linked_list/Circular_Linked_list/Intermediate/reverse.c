// **Reverse Circular List**: Reverse the circular list.

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
    newNode->next = NULL;
    return newNode;
}

// Create a circular linked list with n nodes
Node* createcircularlist(int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    Node* head = createNode(1);
    Node* temp = head;

    for (int i = 2; i <= n; i++)
    {
        temp->next = createNode(i);
        temp = temp->next;
    }

    temp->next = head; // Make the list circular
    return head;
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

Node* reverseCircularList(Node* head)
{
    if (!head || head->next == head)
    {
        return head; // Empty lists or single node list, no need to reverse
    }

    Node *prev = NULL, *current = head, *next = NULL;
    Node* last = head; // Track the last node to fix circularity

    // Reverse the links
    do 
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the link
        prev = current; // Move prev forward
        current = next; // Move current forward
    }while (current != head);
    
    // Fix the circular connection
    head->next = prev; // Old head's next now points to the new last node
    head = prev; // Update head to the new head(prev)

    return head;
}

int main() 
{
    int n;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create a circular linked list with n nodes
    Node* head = createcircularlist(n);

    printf("Original Circular Linked List:\n");
    displayList(head);

    // Reverse the circular linked list
    head = reverseCircularList(head);

    printf("Reversed Circular Linked List:\n");
    displayList(head);

    return 0;
}
