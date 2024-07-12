#include <stdio.h>
#include <stdlib.h>

// Definition of the node in a doubly linked list
struct node {
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

// Function to create a new node
struct node *createNewNode(int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the end of the list
void insertLast(int key) {
    struct node *newnode = createNewNode(key);
    // If the list is empty
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Function to find the sum of all elements in the list
int findSum(struct node *head) {
    int sum = 0;
    struct node *t = head;
    while (t != NULL) {
        sum += t->data;
        t = t->next;
    }
    return sum;
}

// Function to print the list in reverse order
void reversePrint(struct node *tail) {
    if (tail == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *t = tail;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->prev;
    }
    printf("\n");
}

// Function to display the list
void displayList() {
    printf("Linked list: ");
    struct node *t = head;
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int choice, key;
    printf("1. Insert Element\n2. Find Sum\n3. Reverse Print\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter element: ");
            scanf("%d", &key);
            insertLast(key);
        } else if (choice == 2) {
            int sum = findSum(head);
            printf("Sum is: %d\n", sum);
        } else if (choice == 3) {
            reversePrint(tail);
        } else {
            break;
        }

        displayList();
        printf("\n");
    }

    return 0;
}
