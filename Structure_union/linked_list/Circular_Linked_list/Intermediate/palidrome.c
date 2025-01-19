// **Check if List is Palindrome**: Check if the list forms a palindrome.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// To check if the circular linked list is a palindrome
bool isPalindrome(struct Node* head)
{
    if (head == NULL || head->next == head)
    {
        // Empty list or single node list is a palindrome
        return true;
    }

    // Break the circular list temporarily
    struct Node* last = head;
    while (last->next != head)
    {
        last = last->next;
    }
    last->next = NULL; // Tempoearily make it linear

    // Use two pointers to reverse the list and Compare
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* prev = NULL;

    // Find the midpoint using slow and fast pointers
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        // Reverse the first half while finding the middle 
        struct Node* next = slow->next;
        slow->next = prev; 
        prev = slow;
        slow = next;
    }

    // Handle the case for odd number of nodes
    if (fast != NULL)
    {
        slow = slow-> next;
    }

    // Compare the reversed first half with the second half
    struct Node* firsthalf = prev;
    struct Node* secondhalf = slow;
    bool isPalin = true;

    while(firsthalf != NULL && secondhalf != NULL)
    {
        if (firsthalf->data != secondhalf->data)
        {
            isPalin = false;
            break;
        }
        firsthalf = firsthalf->next;
        secondhalf = secondhalf->next;
    }

    // Restore the circular link
    last->next = head;
    return isPalin;
}

void printList(struct Node* head) 
{
    if (head == NULL) return;
    struct Node* temp = head;
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() 
{
    struct Node* head = NULL;

    // Insert elements into the circular linked list
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 2);
    insertEnd(&head, 1);

    printf("Circular Linked List: ");
    printList(head);

    if (isPalindrome(head)) 
    {
        printf("The circular linked list is a palindrome.\n");
    }
    else 
    {
        printf("The circular linked list is not a palindrome.\n");
    }

    return 0;
}
















