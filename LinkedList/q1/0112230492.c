// #include <stdio.h>
// #include <stdlib.h>

// // Link list node structure
// struct ListNode
// {
//   int val;               // Value of the node
//   struct ListNode *next; // Pointer to the next node
// };

// // Function to merge two sorted linked lists
// struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2)
// {
//   // Create a dummy node for the head of the merged list
//   struct ListNode dummy;          // Dummy node, not part of the actual list
//   struct ListNode *tail = &dummy; // Pointer to track the tail of the merged list
//   dummy.next = NULL;              // Initialize the next pointer of the dummy node to NULL

//   // Traverse both lists and merge them
//   while (list1 != NULL && list2 != NULL)
//   {
//     if (list1->val <= list2->val)
//     {                      // Compare values of nodes in list1 and list2
//       tail->next = list1;  // Append list1 node to the merged list
//       list1 = list1->next; // Move to the next node in list1
//     }
//     else
//     {
//       tail->next = list2;  // Append list2 node to the merged list
//       list2 = list2->next; // Move to the next node in list2
//     }
//     tail = tail->next; // Move tail pointer to the last node of the merged list
//   }

//   // Attach the remaining nodes of list1 or list2 to the merged list
//   tail->next = (list1 != NULL) ? list1 : list2;

//   // Return head of the merged list (dummy.next points to the actual merged list)
//   return dummy.next;
// }

// // Function to create a new node with given value
// struct ListNode *newNode(int val)
// {
//   struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode)); // Allocate memory for the new node
//   node->val = val;                                                            // Assign the value to the new node
//   node->next = NULL;                                                          // Initialize the next pointer to NULL (end of list)
//   return node;                                                                // Return the pointer to the new node
// }

// // Function to print a linked list starting from the given head
// void printList(struct ListNode *head)
// {
//   struct ListNode *temp = head; // Temporary pointer to traverse the list starting from head
//   while (temp != NULL)
//   {                           // Traverse until the end of the list (NULL pointer)
//     printf("%d ", temp->val); // Print the value of the current node
//     temp = temp->next;        // Move to the next node
//   }
//   printf("\n"); // Print a newline after printing all nodes
// }

// // Main function
// int main()
// {
//   // Create two sorted linked lists
//   struct ListNode *list1 = newNode(10); // Create nodes for list1
//   list1->next = newNode(13);            // Attach nodes to form a list
//   list1->next->next = newNode(15);

//   struct ListNode *list2 = newNode(2); // Create nodes for list2
//   list2->next = newNode(14);           // Attach nodes to form a list
//   list2->next->next = newNode(26);

//   // Merge the lists
//   struct ListNode *mergedList = mergeTwoLists(list1, list2); // Merge list1 and list2

//   // Print the merged list
//   printf("Merged List: ");
//   printList(mergedList); // Print the merged list

//   return 0; // Exit main function
// }



#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to merge two sorted linked lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // Initialize a dummy node to simplify the code
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;
    
    // Merge the two lists
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    // Append the remaining nodes of l1 or l2
    tail->next = (l1 != NULL) ? l1 : l2;
    
    // Return the head of the merged list
    return dummy.next;
}

// Utility function to create a new node with given value
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    if (!node) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to free memory allocated for the linked list
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Example usage
    struct ListNode* l1 = newNode(1);
    l1->next = newNode(2);
    l1->next->next = newNode(4);
    
    struct ListNode* l2 = newNode(3);
    l2->next = newNode(5);
    l2->next->next = newNode(6);
    
    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);
    
    // Merge the two lists
    struct ListNode* mergedList = mergeTwoLists(l1, l2);
    
    printf("Merged List: ");
    printList(mergedList);
    
    // Free memory
    freeList(mergedList);
    
    return 0;
}
