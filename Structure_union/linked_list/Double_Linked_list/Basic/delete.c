// **Delete First Node**: Delete the first node.
// **Delete Last Node**: Delete the last node.
// **Delete by Value**: Delete a node with a specific value.

#include <stdio.h>
#include <stdlib.h>

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

// Insert at the beginning 
Node* insertatBeginning(Node* head, int data)
{
    Node* newnode = createNode(data);
    if(head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }
    newnode->next = head; // Link new node to current head;
    head->prev = newnode; // Link current head back to new node
    return newnode; // newnode is the new head
}

// Delete the first node
Node* deletefirstnode(Node* head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL; // Return NULL if the list is empty
    }

    Node* temp = head;
    head = temp->next; // Move head to the next node

    if(head != NULL)
    {
        head->prev = NULL; // If the list is not empty, set the prev of new head to NULL
    }

    free(temp); // free the old head
    return head; // return the new head
}

// Delete the last node
Node* deletelastnode(Node* head)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL; // Return NULL if the list is empty
    }
    Node* temp = head;

    // If there is only one node
    if(temp->next == NULL)
    {
        free(temp);
        head = NULL;
        return NULL;
    }

    // Traverse to the last node
    while(temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node 
    }

    // Now temp points to the last node
    temp->prev->next = NULL;
    free(temp);
}

// Delete the node by value
Node* deletemodebyvalue(Node* head, int value)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return NULL; // Return NULL if the list is empty
    }
    Node* temp = head;

    // Traverse to the list to find the node with the given value
    while(temp != NULL && temp->data != value)
    {
        temp = temp->next; // Traverse to the last node 
    }

    if(temp == NULL)
    {
        printf("Value %d not found in the list\n", value);
        return head;
    }

    // If the node to delete is the head
    if(temp == head)
    {
        head = temp->next; // Move head to the next node
        if(head != NULL)
        {
            head->prev = NULL; // Update the new head's prev pointer
        }
        free(temp);
        return head;
    }

    // If the node to delete is in the middle or end
    if(temp->next !=NULL)
    {
        temp->next->prev = temp->prev; // Update the next node's prev pointer
    }

    if(temp->prev !=NULL)
    {
        temp->prev->next = temp->next; // Update the prev node's prev pointer
    }

    free(temp); // Free the node
    return head;
}

void displaylist(Node* head)
{
    Node* temp = head;
    printf("Doubly Linked List: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;

    // Insert nodes at the beginning
    head = insertatBeginning(head, 10);
    head = insertatBeginning(head, 20);
    head = insertatBeginning(head, 30);
    head = insertatBeginning(head, 40);
    head = insertatBeginning(head, 50);

    printf("Original list:\n");
    displaylist(head);

    // Deleting first node
    head = deletefirstnode(head);
    printf("List after deleting the first node:\n");
    displaylist(head);

    // Deleting last node
    deletelastnode(head);
    printf("List after deleting the last node:\n");
    displaylist(head);

    // Deleting with value
    head = deletemodebyvalue(head, 30);
    printf("List after deleting with value:\n");
    displaylist(head);
}
