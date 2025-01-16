// **Merge Two Sorted Lists**: Merge two sorted doubly linked lists.

#include <stdio.h>
#include <stdlib.h>

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

// Merge two sorted lists
Node* mergeSortedLists(Node* head1, Node* head2)
{
    // If one of the list is empty return the other list
    if(!head1)
    {
        return head2;
    }
    if(!head2)
    {
        return head1;
    }

    // Head of the merged list
    Node* mergedHead = NULL;

    // Step1: Initalize the head of the merged list
    if (head1->data <= head2->data)
    {
        mergedHead = head1; // Smaller element becomes the head
        head1 = head1->next; // Move head1 to the next node
    }
    else
    {
        mergedHead = head2; // Smaller element becomes the head
        head2 = head2->next; // Move head1 to the next node
    }

    Node* current = mergedHead; // Pointer to traverse the merged list

    // Step 2: Merge the lists by comparing nodes
    while(head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            // If head1 data is smaller or equal link to merged list
            current->next = head1;
            head1->prev = current; // Update the previous Pointer
            head1 = head1->next; // Move head1 to the next node
        }
        else
        {
            // If head1 data is smaller or equal link to merged list
            current->next = head2;
            head2->prev = current; // Update the previous Pointer
            head2 = head2->next; // Move head1 to the next node
        }
        current = current->next; // Move the current pointer forward
    }

    // Step 3: Attach the remaining nodes
    if (head1)
    {
        // If nodes remain in head1, Attach them to the  merged list
        current->next = head2;
        head1->prev = current;
    }

    if (head2)
    {
        // If nodes remain in head2, Attach them to the  merged list
        current->next = head1;
        head2->prev = current;
    }

    // Step 4: Return the head of the merged list
    return mergedHead;
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

int main() 
{
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Creating first sorted doubly linked list
    list1 = insertatend(list1, 10);
    list1 = insertatend(list1, 20);
    list1 = insertatend(list1, 30);

    // Creating second sorted doubly linked list
    list2 = insertatend(list2, 15);
    list2 = insertatend(list2, 25);
    list2 = insertatend(list2, 35);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merging the two sorted lists
    Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}