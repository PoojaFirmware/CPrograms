// **Split List**: Split the circular list into two circular lists. 

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

void splitList(struct Node* head, struct Node** firstHalf, struct Node** secondHalf) {
    if (head == NULL) 
    {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Use two-pointer technique to find the middle
    while (fast->next != head && fast->next->next != head) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Set the heads of thetwo halves
    *firstHalf = head;
    *secondHalf = slow->next;

    // Make the first half circular
    slow->next = *firstHalf;

    // Make the second half circular
    struct Node* temp = *secondHalf;
    while (temp->next != head) 
    {
        temp = temp->next;
    }
    temp->next = *secondHalf;
}

int main()
{
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 40);
    insertatend(&head, 50);

    printf("Original Circular Linked List:\n");
    displayList(head);

    // Split the list
    struct Node* firstHalf = NULL;
    struct Node* secondHalf = NULL;
    splitList(head, &firstHalf, &secondHalf);

    // Display the two split lists
    printf("First Half:\n");
    displayList(firstHalf);
    printf("Second Half:\n");
    displayList(secondHalf);

    return 0;
}