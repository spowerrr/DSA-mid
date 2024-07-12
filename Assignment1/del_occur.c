#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the doubly linked list
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
void insertEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete all occurrences of a given value
void deleteAllOccurrences(Node **head, int value)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            Node *nodeToDelete = temp;
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            else
            {
                *head = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            temp = temp->next;
            free(nodeToDelete);
        }
        else
        {
            temp = temp->next;
        }
    }
}

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL;
    // Insert values into the doubly linked list
    int values[] = {4, 5, 6, 7, 4, 8, 9, 4};
    for (int i = 0; i < (int)(sizeof(values) / sizeof(values[0])); i++)
    {
        insertEnd(&head, values[i]);
    }

    int valueToDelete;
    printf("Enter value to delete: ");
    scanf("%d", &valueToDelete);

    deleteAllOccurrences(&head, valueToDelete);

    printf("Updated list: ");
    printList(head);

    return 0;
}
