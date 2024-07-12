#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct Node
{
  int data;
  struct Node *prev;
  struct Node *next;
};

// Function to reverse a doubly linked list
struct Node *reverseDoublyLinkedList(struct Node *head)
{
  struct Node *temp = NULL;
  struct Node *current = head;

  // Swap next and prev for all nodes of doubly linked list
  while (current != NULL)
  {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    head = current;
    current = current->prev;
  }

  return head;
}

// Function to insert a new node at the head of a doubly linked list
void insertAtHead(struct Node **headRef, int newData)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = newData;
  newNode->prev = NULL;
  newNode->next = *headRef;
  if (*headRef != NULL)
  {
    (*headRef)->prev = newNode;
  }
  *headRef = newNode;
}

// Function to print a doubly linked list
void printList(struct Node *head)
{
  struct Node *temp = head;
  printf("Forward: ");
  while (temp != NULL)
  {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");

  printf("Backward: ");
  while (head->next != NULL)
  {
    head = head->next;
  }
  while (head != NULL)
  {
    printf("%d ", head->data);
    head = head->prev;
  }
  printf("\n");
}

int main()
{
  struct Node *head = NULL;

  // Insert elements at the head of the doubly linked list
  insertAtHead(&head, 4);
  insertAtHead(&head, 3);
  insertAtHead(&head, 2);
  insertAtHead(&head, 1);

  printf("Original doubly linked list:\n");
  printList(head);

  // Reverse the doubly linked list
  head = reverseDoublyLinkedList(head);

  printf("\nReversed doubly linked list:\n");
  printList(head);

  return 0;
}
