// **Swap Pairs**: Swap every two adjacent nodes.

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

Node * swappairs(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        // No swapping needed if list is empty or has only one node
        return head; 
    }

    Node* current = head;
    Node* newhead = current->next; // The new head willbe the second node

    while(current && current->next)
    {
        Node* nextpair = current->next->next; // Save the next Pairs
        Node* second = current->next; // The second node of the Pairs

        // Swap the two nodes
        second->next = current;
        second->prev = current->prev;
        if (current->prev)
        {
            current->prev->next = second;
        }
        current->prev = second;
        current->next = nextpair;

        if(nextpair)
        {
            nextpair->prev = current;
        }

        // Move to the next Pairs
        current = nextpair;
    }
    return newhead;
}

int main() 
{
    Node* head = NULL;

    // Create a doubly linked list
    head = insertatend(head, 1);
    head = insertatend(head, 2);
    head = insertatend(head, 3);
    head = insertatend(head, 4);
    head = insertatend(head, 5);
    head = insertatend(head, 6);

    printf("Original list: ");
    printList(head);

    // Swap every two adjacent nodes
    head = swappairs(head);

    printf("List after swapping pairs: ");
    printList(head);

    return 0;
}
























