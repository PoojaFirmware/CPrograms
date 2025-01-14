#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* prev; 
    struct Node* next;
} Node;

// Create a node 
Node* createNode(int data)
{
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the beginning 
Node* insertatBeginning(Node* head, int data)
{
    Node* newnode = createNode(data);
    if (head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }
    newnode->next = head; // Link new node to current head;
    head->prev = newnode; // Link current head back to new node
    return newnode; // newnode is the new head
}

void displaylist(Node* head)
{
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node* reverseList(Node* head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to reverse\n");
        return NULL;
    }

    Node* temp = NULL;
    Node* current = head;

    // Swap the next and prev pointers for each node
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node (reversed now)
    }

    // Update the head to the last node
    if (temp != NULL)
    {
        head = temp->prev; // temp->prev points to the last node of the original list
    }
    return head;
}

int main()
{
    Node* head = NULL;

    // Inserting nodes at the beginning
    head = insertatBeginning(head, 10);
    head = insertatBeginning(head, 20);
    head = insertatBeginning(head, 30);
    head = insertatBeginning(head, 40);
    head = insertatBeginning(head, 50);

    printf("Original list:\n");
    displaylist(head);

    // Reversing the list
    head = reverseList(head);

    printf("Reversed list:\n");
    displaylist(head);

    return 0;
}
