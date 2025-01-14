#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the length of a linked list
int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

// Function to find the intersection point of two linked lists
struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    // Align the starting points
    struct Node* longer = len1 > len2 ? head1 : head2;
    struct Node* shorter = len1 > len2 ? head2 : head1;

    int diff = abs(len1 - len2);
    for (int i = 0; i < diff; i++) {
        longer = longer->next;
    }

    // Traverse both lists to find the intersection
    while (longer != NULL && shorter != NULL) {
        // Debugging: Print the memory addresses
        printf("Checking nodes - List 1: %p, Data: %d | List 2: %p, Data: %d\n",
               (void*)longer, longer->data, (void*)shorter, shorter->data);

        if (longer == shorter) {
            printf("Intersection found at node address: %p, Data: %d\n",
                   (void*)longer, longer->data);
            return longer; // Intersection point
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    printf("No intersection found.\n");
    return NULL; // No intersection
}

// Helper function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Test the function
int main() {
    // Create two linked lists
    struct Node* common = createNode(15);
    common->next = createNode(30);

    struct Node* list1 = createNode(10);
    list1->next = createNode(20);
    list1->next->next = common;

    struct Node* list2 = createNode(5);
    list2->next = common;

    // Print the lists
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    // Find the intersection
    struct Node* intersection = findIntersection(list1, list2);

    if (intersection) {
        printf("Intersection point: Data = %d\n", intersection->data);
    } else {
        printf("No intersection point.\n");
    }

    return 0;
}
