// **Check Palindrome**: Check if the list is a palindrome.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Insert at the end
Node* insertatend(Node* head, int data)
{
    Node* newnode = createNode(data);
    if(head == NULL)
    {
        return newnode; // New node becomes the head if the list is empty
    }

    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next; // Traverse to the last node 
    }

    temp->next = newnode; // Link new node to current head;
    newnode->prev = temp; // Link current head back to new node
    return head; // newnode is the new head
}

void printList(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

bool isPalindrome(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        return true; // Single node or empty list is always a palindrome
    }

    // Find the tail of list
    Node* tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Compare element from the start and end of the list
    Node* start = head;
    Node* end = tail;

    while(start != NULL && end != NULL && start != end && start->prev != end)
    {
        if (start->data != end->data)
        {
            return false; // Not a palidrome
        }
        start = start->next;
        end = end->prev;
    }
    return true; // List is a palidrome
}

int main() 
{
    Node* head = NULL;

    // Create a doubly linked list
    head = insertatend(head, 1);
    head = insertatend(head, 2);
    head = insertatend(head, 3);
    head = insertatend(head, 2);
    head = insertatend(head, 1);

    printf("Doubly linked list: ");
    printList(head);

    // Check if the list is a palindrome
    if (isPalindrome(head)) {
        printf("The list is a palindrome.\n");
    } else {
        printf("The list is not a palindrome.\n");
    }

    return 0;
}


























