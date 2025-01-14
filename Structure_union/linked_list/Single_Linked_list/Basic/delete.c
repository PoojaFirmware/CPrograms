// **Delete First Node**: Function to delete the first node.
// **Delete Last Node**: Function to delete the last node.
// **Delete by Value**: Delete a node with a specific value.

#include <stdio.h>
#include <stdlib.h>

// The structure for linked list for Node
struct node
{
    int data;            // Store data of the node
    struct node* next;   // Pointer to the next node in the list
};

// Create a new node with given data
struct node* createNode(int data)
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

// Delete the first node of linked list
struct node* deletefirstnode(struct node* head)
{
    if(head == NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next; //Move head to the main node
    free(temp); // Free the old head

    return head; 
}

struct node* deletelastnode(struct node* head)
{
    if (head == NULL)
    {
        printf("The list is already empty");
        return NULL;
    }

    if (head->next == NULL)
    {
        // Only one node in the list
        free(head);
        return NULL;
    }

    struct node* current = head;
    while (current->next->next != NULL)
    {
        current = current->next; //Move to the second-last node
    }
    
    free(current->next); // free the last node
    current->next = NULL;

    return head;
}

/*
This function deletes a node with a specific value from a linked list.

1. **Check if List is Empty**:
   - If `head` is `NULL`, the list is empty, so there’s nothing to delete. We print a message and return `NULL`.

2. **Check if the Value is in the First Node**:
   - If the value to delete is in the `head` node (first node):
     - We store `head` in a temporary variable (`temp`).
     - Move `head` to the next node (`head->next`), so the second node becomes the new head.
     - Free the old head node (`temp`) to release memory.
     - Return the updated head of the list.

3. **Traverse the List to Find the Node**:
   - If the node isn’t the head, we search the list for the node with the target value.
   - We use two pointers:
     - `current` to track the node we’re currently on.
     - `prev` to remember the previous node, which is needed to skip over the node we’ll delete.
   - We move `current` through the list until we find the value or reach the end.

4. **Delete the Node if Found**:
   - If the node with the target value is found:
     - We link `prev->next` to `current->next`, effectively skipping the `current` node.
     - Free `current` to release memory.

5. **Return the Modified List**:
   - We return the updated head pointer, which may be unchanged if the head wasn’t deleted.
*/

// Delete a node by value 
struct node* deletebyvalue(struct node* head, int value)
{
    if (head == NULL)
    {
        printf("The list is already empty");
        return NULL;
    }

    // If the node to be deleted is the head node
    if (head->data == value)
    {
        struct node* temp = head;
        head = head->next; // Move head to the next node 
        free(temp);        // free the old head
        return head;       // return the new head
    }

    struct node* current = head;
    struct node* prev = NULL;

    //Traverse the list to find the node with the value
    while (current != NULL && current->data != value)
    {
        prev = current;  // Track of the previous node
        current = current->next; //Move to the next node
    }

    // If the node with value is not found
    if (current == NULL)
    {
        printf("Value %d not found in the list\n", value);
        return head;
    }
    
    // Link previos node to the next node, skipping the target node
    prev->next = current->next;
    free(current); // free the node with target value

    return head;
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
    struct node* head = createNode(10);
    struct node* second = createNode(20);
    struct node* third = createNode(30);

    head->next = second;
    second->next = third;
    third->next = NULL;

    printf("Original list: ");
    printlist(head);

    // Delete the first node
    head = deletefirstnode(head);
    printf("After deleting first node: ");
    printlist(head);

    // Delete the last node
    head = deletelastnode(head);
    printf("After deleting last node: ");
    printlist(head);

    // Delete node by value
    head = deletebyvalue(head, 2);
    printf("After deleting node with value 2: ");
    printlist(head);

    // Free remaining nodes if any
    head = deletefirstnode(head);

    return 0;
}
