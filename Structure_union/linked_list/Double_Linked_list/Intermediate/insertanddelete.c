// Insert at Specific Position: Insert a node at a given position.
// Delete at Specific Position: Delete a node at a specified position.

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

// Insert at specific position
void insertatposition(Node** head, int data, int position)
{
    Node* newNode = createNode(data);
    if (position == 1)
    {
        newNode->next = *head;
        if (*head)
        {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for(int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of bounds.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// Delete a node at a specific position
void deleteatposition(Node** head, int position)
{
    if(*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;
    if(position == 1)
    {
        *head = temp->next;
        if(head)
        {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for(int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        printf("Position out of bounds.\n");
        return;
    }

    if(temp->next)
    {
        temp->next->prev = temp->prev;
    }
    if(temp->prev)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertatposition(&head, 10, 1);
    insertatposition(&head, 20, 2);
    insertatposition(&head, 30, 3);
    printf("List after inserting 10, 20, 30: ");
    printList(head);

    insertatposition(&head, 15, 2);
    printf("List after inserting 15 at position 2: ");
    printList(head);

    deleteatposition(&head, 3);
    printf("List after deleting node at position 3: ");
    printList(head);

    deleteatposition(&head, 1);
    printf("List after deleting node at position 1: ");
    printList(head);

    return 0;
}