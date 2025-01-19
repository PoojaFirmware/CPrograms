// **Josephus Problem**: Solve the Josephus problem using a circular list.

#include<stdio.h>
#include<stdlib.h>

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

struct Node* createCircularList(int n)
{
    struct Node* head = NULL;
    struct Node* temp = NULL;
    struct Node* tail = NULL;

    for(int i = 1; i <= n; i++)
    {
        struct Node* newNode = createNode(i);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = head; // Point to itself to make it circular
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head; // Maintain the circular property
        }
        
    }
    return head;
}

void displayList(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Current List: ");
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head: %d)\n", head->data);
}

int josephus(struct Node** head, int k)
{
    struct Node* prev = NULL;
    struct Node* curr = *head;
    
    while(curr->next != curr)
    {
        // Traverse k-1 nodes
        for(int i = 1; i < k; i++)
        {
            prev = curr;
            curr = curr->next;
        }

        // Remove the k-th node
        prev->next = curr->next;
        printf("Eliminated: %d\n", curr->data);
        free(curr);
        curr = prev->next;

        displayList(*head);
    }

    *head = curr;
    return curr->data;
}

int main() 
{
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step rate (k): ");
    scanf("%d", &k);

    // Create a circular linked list with `n` nodes
    struct Node* head = createCircularList(n);

    // Display the initial list
    printf("Initial Circular Linked List:\n");
    displayList(head);

    // Solve the Josephus problem
    int survivor = josephus(&head, k);
    printf("The last remaining person is at position: %d\n", survivor);

    // Free the remaining node
    free(head);

    return 0;
}
