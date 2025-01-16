// **Rotate by K Nodes**: Rotate the list by `k` nodes.


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

Node* rotateByKth(Node* head, int k)
{
    if (head == NULL || k <= 0)
    { 
        return head;
    }

    // Step 1: Find its length of list
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL)
    {
        temp = temp->next;
        length++;
    }

    // Step 2: Handle cases where k >= length
    k = k % length; // If k is greater than the length, use k % length
    if (k == 0)
    {
        return head; // No rotation needed
    }

    // Step 3: Traverse to the kth node
    Node* current = head;
    for(int i = 1; i < k; i++)
    {
        current = current->next;
    }

    // Step4: Update pointers to perform the functions
    Node* newhead = current->next;
    newhead->prev = NULL;
    current->next = NULL;

    temp->next = head;
    head->prev = temp;

    return newhead;
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

    // Rotate the list by k nodes
    int k = 2;
    head = rotateByKth(head, k);

    printf("List after rotating by %d nodes: ", k);
    printList(head);

    return 0;
}