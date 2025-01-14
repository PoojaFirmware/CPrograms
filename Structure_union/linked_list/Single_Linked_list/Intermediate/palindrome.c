// Check if the list is a palindrome
// Approach:
// Step 1: Use the slow and fast pointer technique to find the middle of the list.
// Step 2: Reverse the second half of the list.
// Step 3: Compare the first half and the reversed second half of the list.
// Step 4: If both halves are identical, the list is a palindrome. Otherwise, it is not.

#include <stdio.h>
#include <stdlib.h>

// The structure for linked list for node
struct node
{
    int data;            // Store data of the node
    struct node* next;   // Pointer to the next node in the list
};

// Create a new node with given data
struct node* createnode(int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1); // Exits the program if memory allocation fails
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* reverseList (struct node* head)
{
    struct node* prev = NULL; // Initalise previous pointer as NULL;
    struct node* current = head; // Start with the head node
    struct node* next = NULL; // Temporary pointer to store next node

    while (current != NULL)
    {
        next = current->next;       // Store next node
        current->next = prev;       // Reverse the current node's pointer
        prev = current;             // Move prev one step forward
        current = next;             // Move current one step forward
    }
    head = prev; // Update head to the new front of the list
    return head; 
}

int ispalindrome(struct node* head)
{
    // If the list is empty or has only one element, its a palindrome
    if (head == NULL || head->next == NULL)
    {
        return 1;
    }

    //step 1: Find the middle of the list using slow and fast pointer
    struct node* slow = head;
    struct node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next; // Move slow pointer one step
        fast = fast->next->next; // MOve fast pointer two steps
    }

    // Step 2: Reverse the second half of the list
    struct node* secondhalf = reverseList(slow);
    struct node* firsthalf = head;

    // Step 3: Compare both halves
    while(secondhalf != NULL)
    {
        if(firsthalf->data != secondhalf->data)
        {
            return 0; // List is not a palindrome
        }
        firsthalf = firsthalf->next;
        secondhalf = secondhalf->next;
    }

    return 1; // List is a palindrome
}


// Printing the Linked List
void printlist(struct node* head)
{
    //struct node* current = head;
    while (head != NULL)
    {
        printf("%d -->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 2 -> 1 -> NULL
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(2);
    head->next->next->next->next = createnode(1);

    printf("Linked List: \n");
    printlist(head);

    // Check if the linked list is a palindrome
    if (ispalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }
}


