#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev; 
    int data;
    struct node *next;
} *head = NULL;


struct node *createNewNode(int x) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
};


void insertLast(int key) {
    struct node *newnode = createNewNode(key);
    // If the list is empty
    if(head == NULL) {
        head = newnode;
    }
    else {
        struct node *t = head;

        while(t->next != NULL){
            t = t->next;
        }

        // Now t is the last node
        t->next = newnode;
        newnode->prev = t;
    }
}


int findSum() {
    int first = head->data;
    struct node *temp = head;

    if(head->next == NULL) {
        int sum = head->data;
        return sum;
    }
    else {
        while(temp->next != NULL) {
            temp = temp->next;
        }

        int last = temp->data;
        int sum = first + last;

        return sum;
    }
}


void displayList() {
    printf("Linked list: ");
    struct node *t = head;

    while(t != NULL) {
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");
}


int main() {
    int choice, key;
    printf("1.InsertElement 2.FindSum\n");

    while(1){
        printf("Enter choice: ");
        scanf("%d", &choice);
        if(choice == 1) {
            printf("Enter element: ");
            scanf("%d", &key);
            insertLast(key);
        }
        else if(choice == 2) {
            int sum = findSum();
            printf("Sum of the first and the last element is: %d\n", sum);
        }
        else{
            break;
        }

        displayList();
        printf("\n");
    }
}