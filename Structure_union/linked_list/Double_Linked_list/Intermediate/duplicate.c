// **Remove Duplicates**: Remove duplicate nodes.

#include <stdio.h>
#include <stdlib.h>

// Double linked list
typedef struct Node
{
    int data;
    struct Node* prev; 
    struct Node* next;
}Node;

// create a node 
Node* createNode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if(!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the end
Node* insertatend(Node* head, int data)
{
    Node* newnode = createNode(data);
    if(head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node 
    }

    temp->next = newnode; // Link new node to current head;
    newnode->prev = temp; // Link current head back to new node
    return head; // newnode is the new head
}

void removeduplicates(Node* head)
{
    // If the lists is empty or contains only one node, no duplicates to remove 
    if (head == NULL)
    {
        return;
    }

    // Outer loop: Traverse the list using the current pointer
    Node* current = head;
    while(current != NULL)
    {
        // Inner loop: Compare the current node with the rest of the list
        Node* runner = current->next;
        while(runner != NULL)
        {
            // Check if the current node's data matches the runner's data
            if (runner->data == current->data)
            {
                // Duplicates found: Remove the runner node
                Node* duplicate = runner;

                // Adjust the pointers of runner's previous and next nodes
                if (runner->next != NULL)
                {
                    runner->next->prev = runner->prev;
                }
                runner->prev->next = runner->next;
                runner = runner->next;
                free(duplicate);
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    // Create a doubly linked list
    head = insertatend(head, 10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 20); // Duplicate
    head = insertatend(head, 40);
    head = insertatend(head, 30); // Duplicate
    head = insertatend(head, 50);

    // Print the original list
    printf("Original list: ");
    printList(head);

    // Remove duplicates from the list
    removeduplicates(head);

    // Print the modified list
    printf("List after removing duplicates: ");
    printList(head);

    return 0;
}

















