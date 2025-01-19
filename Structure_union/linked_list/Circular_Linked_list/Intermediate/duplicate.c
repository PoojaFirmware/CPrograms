// **Remove Duplicates**: Remove duplicate nodes from the list.

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

struct Node* insertatend(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        return newNode; // New node is now the head
    }

    // Find the last node
    struct Node* temp = *head;
    while(temp->next != *head)
    {
        temp = temp->next; // Traverse to the last node
    }

    // Update pointers for the circular structure
    temp->next = newNode;
    newNode->next = *head;
    return *head; // return the existing head
}

void removeduplicate(Node** head)
{
    // If the list is empty or contains only one node, there are no duplicate 
    if (*head == NULL || (*head)->next == *head)
    {
        return;
    } 

    Node *current = *head; // Pointer to Traverse the list
    Node *prev, *temp; // 'Prev' tracks the node before 'temp, 'temp is used for duplicate checks

    // Outer loop to pick each node one by one
    do
    {
        prev = current; // Start 'prev' from the current node
        temp = current->next; // Start 'temp' from the next node

        // Inner loop to check all subsequent nodes for Duplicates
        while(temp != *head)
        {
            if(current->data == temp->data)
            {
                // Duplicate found, remove the node
                prev->next = temp->next; // Bypass the duplicate node
                free(temp);  // free the memory of the duplicate node
                temp = prev->next; // Move 'temp to the next node
            }
            else
            {
                // If no duplicate, move both 'prev' and 'temp' forward
                prev = temp;
                temp = temp->next;            
            }
        }
        // Move current to the next node in the list
        current = current->next;
    } while (current->next != *head); // stop when we return to the head node
}

int main() 
{
    Node* head = NULL;

    // Adding nodes to the list and updating head
    head = insertatend(&head, 10);
    head = insertatend(&head, 20);
    head = insertatend(&head, 30);
    head = insertatend(&head, 20); // Duplicate
    head = insertatend(&head, 40);
    head = insertatend(&head, 10); // Duplicate

    printf("Original list:\n");
    displayList(head);

    // Remove duplicates
    removeduplicate(&head);

    printf("List after removing duplicates:\n");
    displayList(head);

    return 0;
}