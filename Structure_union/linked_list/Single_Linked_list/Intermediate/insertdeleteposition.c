// Insert and Delete at a Specific Position: Insert a node at a given position.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
    
};

// Insert at a specific position 
void InsertAtposition(struct Node* *head, int data, int position)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If inserting at the head (position 0)
    if (position == 0)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    // Traverse to the node just before the desired position
    for(int i = 0; i < position - 1 && current != NULL; i++)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Position out of range");
        free(newNode);  // Free memory to avoid memory leak
        return;
    }

    newNode->next = current->next;
    current->next = newNode;   
}

void printlist(struct Node* head)
{
    //struct node* current = head;
    while (head != NULL)
    {
        printf("%d -->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Delete a position from a linked list
void DeleteAtposition(struct Node* *head, int position)
{
    if (*head == NULL)
        return;

    struct Node* temp = *head;
    
    // If the node to be deleted is the head node
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }


    struct Node* prev = NULL;
    for(int i = 0; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position out of range");
        return;
    }

    prev->next = temp->next;
    free(temp); 
}

int main()
{
    struct Node* head = NULL; // Initalize an empty linked list
    
    // Directly defined method
    //Insert at a specific position of the linked list
    // InsertAtposition(&head, 10, 0);
    // InsertAtposition(&head, 20, 1);
    // InsertAtposition(&head, 30, 2);
    
    // printf("Inserting at the specific position in linked list: ");
    // printlist(head);

    // User defined method
    int data, position, choice;

        while (1) {
        printf("\nChoose an option:\n");
        printf("1. Insert a node at a specific position\n");
        printf("2. Delete a node at a specific position\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                InsertAtposition(&head, data, position);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                DeleteAtposition(&head, position);
                break;

            case 3:
                printf("Current linked list: ");
                printlist(head);
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}