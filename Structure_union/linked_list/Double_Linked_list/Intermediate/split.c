#include <stdio.h>
#include <stdlib.h>

// Double linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (!newnode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

// Insert at the end of the list
Node* insertatend(Node* head, int data) {
    Node* newnode = createNode(data);
    if (head == NULL) {
        return newnode; // New node becomes the head if the list is empty
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next; // Traverse to the last node
    }

    temp->next = newnode; // Link new node to current head
    newnode->prev = temp; // Link current head back to new node
    return head;          // Return the head
}

// Split the list into two halves
void splitList(Node* head, Node** firstHalf, Node** secondHalf) {
    if (head == NULL) {
        *firstHalf = NULL;
        *secondHalf = NULL;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Use two-pointer technique to find the middle
    while (fast && fast->next) {
        fast = fast->next->next;
        if (fast) {
            slow = slow->next;
        }
    }

    *firstHalf = head;
    *secondHalf = slow->next;

    if (*secondHalf) {
        (*secondHalf)->prev = NULL;
    }
    slow->next = NULL;
}

// Print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate splitting the list
int main() {
    Node* head = NULL;
    Node* firstHalf = NULL;
    Node* secondHalf = NULL;

    // Creating a doubly linked list
    head = insertatend(head, 10);
    head = insertatend(head, 20);
    head = insertatend(head, 30);
    head = insertatend(head, 40);
    head = insertatend(head, 50);

    printf("Original list: ");
    printList(head);

    // Splitting the list
    splitList(head, &firstHalf, &secondHalf);

    printf("First half: ");
    printList(firstHalf);

    printf("Second half: ");
    printList(secondHalf);

    return 0;
}
