// **Search in List**: Search for a specific value.

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a nodes
struct Node 
{
    int data;
    struct Node* next;
};

// Create a new nodes
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertatend(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode; // Empty lists: point the new node to itself
        *head = newNode; // Update the head
        return; 
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

int searchValue(struct Node* head, int target)
{
    if (head == NULL) //If list is empty
    {
        return 0; // Value not found
    }

    struct Node* temp = head;
    do
    {
        if(temp->data == target)
        {
            return 1; // Value found
            temp = temp->next;
        }
    } while (temp != head);
    
    return 0;
}

int main() 
{
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 40);

    // Display the list
    printf("Circular Linked List: ");
    displayList(head);

    // Search for a specific value in the list
    int target = 30;
    if (searchValue(head, target)) 
    {
        printf("Value %d found in the list.\n", target);
    } 
    else 
    {
        printf("Value %d not found in the list.\n", target);
    }

    target = 50; // Search for a value not in the list
    if (searchValue(head, target)) 
    {
        printf("Value %d found in the list.\n", target);
    } 
    else 
    {
        printf("Value %d not found in the list.\n", target);
    }

    return 0;
}