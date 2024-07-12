#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};



// Function to find a pair whose sum equals to a given value x
void pairSum(struct Node *head, int x) {
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    struct Node *first = head;
    struct Node *second= head;
    while (second->next!= NULL)
        second= second->next;

    // To track if we find a pair or not
    int found = 0;

    // The loop terminates when two pointers
    // cross each other (second->next == first),
    // or they become same (first == second)
    while (first !=second && second->next!= first) {
        // Pair found
        if((first->data + second->data) == x) {
            found = 1;
            printf("(%d, %d)\n", first->data, second->data);

            // Move first in forward direction
            first= first->next;

            // Move second in backward direction
            second = second->prev;
        }
        else{
            if((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    // If pair is not present
    if(found == 0)
        printf("No pair found\n");
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = temp->prev = NULL;

    if(!(*head)) {
        *head = temp;
    }
    else{
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

int main() {
    struct Node *head = NULL;
    int x,data;

    printf("Enter elements to insert into the doubly linked list (enter 0 to stop):\n");
    while (1) {
        printf("Enter element: ");
        scanf("%d", &data);
        if (data == 0) {
            break;
        }
        insert(&head, data);
    }

    printf("Enter the value of x to find pairs: ");
    scanf("%d", &x);

    pairSum(head, x);

    return 0;
}

