// **Rotate List by K Nodes**: Rotate the circular list by `k` nodes.

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

void rotateList(struct Node** head, int k)
{
    if (*head == NULL || k <= 0)
    {
        printf("Invalid rotation value or empty list\n");
        return;
    }

    struct Node* temp = *head;
    int count = 1;

    // Find the length of the circular linked list
    struct Node* last = *head;
    while(last->next != *head)
    {
        last = last->next;
    }

    // Normalise k in case its greater than the length of the list
    int length = count;
    struct Node* current = *head;
    while(current->next != *head)
    {
        count++;
        current = current->next;
    }
    length = count;
    k = k % length; // Handle cases wherr k > length

    // No rotation needed if k is 0 or a multiple of length
    if (k == 0)
    {
        return;
    }

    // Move the temp pointer to the (k+1)th node
    count = 1;
    temp = *head;
    while(count < k && temp->next != *head)
    {
        temp = temp->next;
        count++;
    }

    // Adjust the links to rotate the list
    *head = temp->next; // The (k+1)th node becomes the new head 
    temp->next = NULL; // Break the circular link temporarily
    last->next = *head;  // Reconnect 
}

int main()
{
    struct Node* head = NULL;

    // Insert elements into the circular linked lists
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);
    insertEnd(&head, 60);

    printf("Original circular linked list\n");
    displayList(head);

    int k = 2; // Number of nodes to rotate
    rotateList(&head, k);

    printf("Rotate circular linked list by %d nodes: ", k);
    displayList(head);

    return 0;
}
