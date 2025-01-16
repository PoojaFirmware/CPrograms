// **Nth Node from End**: Find the nth node from the end.

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

Node* findNthfromend(Node* head, int n)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }

    // Step1: Traverse the list to find its length
    Node* temp = head;
    int length = 0;
    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    // Step 2: Check if n is valid
    if (n > length || n <= 0)
    {
        printf("Invalid value for n: %d\n", n);
        return NULL;
    }

    // Step 3: Find the (length - n + 1)th node from the beginning 
    int target = length - n + 1;
    temp = head;
    for (int i = 1; i < target; i++)
    {
        temp = temp->next;
    }
    
    return temp;
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) {
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
    head = insertatend(head, 40);
    head = insertatend(head, 50);

    printf("Original list: ");
    printList(head);

    // Find the nth node from the end
    int n = 2;
    Node* nthNode = findNthfromend(head, n);
    if (nthNode != NULL) {
        printf("The %dth node from the end is: %d\n", n, nthNode->data);
    }

    return 0;
}