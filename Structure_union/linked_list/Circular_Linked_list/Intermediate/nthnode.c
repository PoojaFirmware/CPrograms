// **Nth Node from Start**: Find the nth node from the start.

#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list 
struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert a node at the end of the circular linked list
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

int findnthnode(struct Node* head, int n)
{
    if (head == NULL || n <= 0)
    {
        printf("Invalid input or empty list\n");
        return -1;
    }

    struct Node* temp = head;
    int count = 1;

    // Traverse the list to find the nth node
    while (count < n)
    {
        temp = temp->next;
        // If we reach back to the head before finding nth node, n is out of bounds
        if (temp == head)
        {
            printf("The list has fewer than %d nodes\n", n);
            return -1;
        }
        count++;
    }
    return temp->data;
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

    // Insert elements into the circular linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Circular Linked List: ");
    displayList(head);

    int n = 3; // Node position to find
    int nthNode = findnthnode(head, n);
    if (nthNode != -1) 
    {
        printf("The %dth node from the start is: %d\n", n, nthNode);
    }

    return 0;
}










