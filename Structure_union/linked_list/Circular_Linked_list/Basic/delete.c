// **Delete First Node**: Delete the first node.
// **Delete Last Node**: Delete the last node.
// **Delete at Specific Position**: Delete a node at a given position.

#include <stdio.h>
#include <stdlib.h>

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

// Insert at the end
void insertatend(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {  // Empty list
        newNode->next = newNode;  // Point to itself
        *head = newNode;  // Update head
        return;
    }

    struct Node* temp = *head;
    while (temp->next != *head) {  // Traverse to the last node
        temp = temp->next;
    }
    temp->next = newNode;  // Add new node at the end
    newNode->next = *head;  // Make it circular
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

void deleteFirstnode(struct Node** head)
{
    // Step1: Check if the list is empty
    if(*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = *head;

    // Step2:Handle the case where this is only one node
    if (temp->next == *head) // Only one node in the lists 
    {
        *head = NULL; // Set head to NULL
        free(temp);  // Free the single node
        return;
    }

    // Step3: Traverse to the last node
    struct Node* current = *head;
    while(current->next != *head)
    {
        current = current->next;
    }

    // Step4: Update the last node's next pointer to point to the second node
    current->next = (*head)->next;

    // Step5: Update the head pointer to the second node
    *head = (*head)->next;

    free(temp); // free old head node
}

void deleteLastnode(struct Node** head)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = *head;

    // Step 2: Handle the case where there is only one node
    if (temp->next == *head) // Only one node in the list
    {
        *head = NULL;        // Set head to NULL
        free(temp);          // Free the single node
        return;
    }

    // Step 3: Traverse to the second last node
    struct Node* prev = NULL;
    while (temp->next != *head) // Loop until temp points to the last node
    {
        prev = temp;           // Keep track of the previous node
        temp = temp->next;     // Move temp to the next node
    }

    // Step 4: Update the second last node's next pointer to point to head
    prev->next = *head;        // Link the second last node to head

    // Step 5: Free the last node
    free(temp);                // Free the memory of the last node
}

void deleteAtPosition(struct Node** head, int position)
{
    // Step 1: Check if the list is empty
    if (*head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp = *head;

    // Step 2: Handle the case where there is only one node
    if (temp->next == *head) // Only one node in the list
    {
        *head = NULL;        // Set head to NULL
        free(temp);          // Free the single node
        return;
    }

    // If deleting the first node
    if (position == 1)
    {
        deleteFirstnode(head);
        return;
    }

    // Traverse to the node before the position
    struct Node* prev = NULL;
    int count = 1;
    while (count < position && temp->next != *head)
    {
        prev = temp;
        temp = temp->next;
        count++;
    }
    
    // Check if the position is valid
    if (count != position)
    {
        printf("Invalid Position\n");
        return;
    }

    // Update the previous node's next pointer and free the current node
    prev->next = temp->next;
    free(temp);
}

int main()
{
    struct Node* head = NULL;

    // Insert nodes into the circular linked list
    insertatend(&head, 10);
    insertatend(&head, 20);
    insertatend(&head, 30);
    insertatend(&head, 40);

    printf("Original Circular Linked List:\n");
    displayList(head);

    // Delete the first node
    printf("\nDeleting the first node...\n");
    deleteFirstnode(&head);
    displayList(head);

    // Delete the last node
    printf("\nDeleting the last node...\n");
    deleteLastnode(&head);
    displayList(head);

    // Delete a node at a specific position
    printf("\nDeleting the node at position 2...\n");
    deleteAtPosition(&head, 2);
    displayList(head);

    return 0;
}
















