#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *prev;
  struct node *next;
} *head = NULL, *tail = NULL;

struct node *createNewNode(int x)
{
  struct node *newnode = (struct node *)malloc(sizeof(struct node));
  newnode->data = x;
  newnode->prev = NULL;
  newnode->next = NULL;
  return newnode;
}

void insertBeginning(int x)
{
  struct node *newnode = createNewNode(x);
  if (head == NULL)
  { // if the list is empty
    head = newnode;
    tail = newnode;
  }
  else
  {
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
  }
}

void insertLast(int x)
{
  struct node *newnode = createNewNode(x);
  if (tail == NULL)
  {
    head = newnode;
    tail = newnode;
  }
  else
  {
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
  }
}

void insertAt(int pos, int x)
{
  if (pos < 0)
  { // invalid position
    printf("Invalid position\n");
    return;
  }
  else if (pos == 0)
  { // insert at the beginning
    insertBeginning(x);
    return;
  }
  else
  { // insert at the given position
    int idx = 0;
    struct node *t = head;
    while (t != NULL && idx < pos - 1)
    {
      idx++;
      t = t->next;
    }
    if (t != NULL)
    {
      struct node *newnode = createNewNode(x);
      newnode->next = t->next;
      newnode->prev = t;
      if (t->next != NULL)
      { // if t is not the last node
        t->next->prev = newnode;
      }
      else
      {
        tail = newnode;
      }
      t->next = newnode;
    }
    else
    {
      printf("Position exceeds the length of the list. %d is not inserted.\n",
             x);
    }
  }
}

void deleteFirst()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct node *t = head;
  if (head == tail)
  {
    head = NULL;
    tail = NULL;
  }
  else
  {
    head = head->next;
    head->prev = NULL;
  }
  free(t);
}

void deleteLast()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return;
  }
  struct node *t = tail;
  if (head == tail)
  {
    head = NULL;
    tail = NULL;
  }
  else
  {
    tail = tail->prev;
    tail->next = NULL;
  }
  free(t);
}

void deleteAt(int pos)
{
  if (pos < 0)
  {
    printf("Invalid position\n");
    return;
  }
  if (pos == 0)
  {
    deleteFirst();
    return;
  }
  int idx = 0;
  struct node *t = head;
  while (t != NULL && idx < pos)
  {
    idx++;
    t = t->next;
  }
  if (t == NULL)
  {
    printf("Position exceeds the length of the list\n");
    return;
  }
  if (t->next != NULL)
  {
    t->next->prev = t->prev;
  }
  if (t->prev != NULL)
  {
    t->prev->next = t->next;
  }
  if (t == tail)
  {
    tail = t->prev;
  }
  free(t);
}

void deleteOccurrences(int x)
{
  struct node *t = head;
  while (t != NULL)
  {
    if (t->data == x)
    {
      struct node *temp = t;
      if (t->prev != NULL)
      {
        t->prev->next = t->next;
      }
      else
      { // t is head
        head = t->next;
      }
      if (t->next != NULL)
      {
        t->next->prev = t->prev;
      }
      else
      { // t is tail
        tail = t->prev;
      }
      t = t->next;
      free(temp);
    }
    else
    {
      t = t->next;
    }
  }
}

int search(int element)
{
  struct node *t = head;
  int idx = 0;
  while (t != NULL)
  {
    if (t->data == element)
    {
      return idx;
    }
    t = t->next;
    idx++;
  }
  return -1;
}

int findMax()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return -1;
  }
  struct node *t = head;
  int max = head->data;
  while (t != NULL)
  {
    if (t->data > max)
    {
      max = t->data;
    }
    t = t->next;
  }
  return max;
}

int findMin()
{
  if (head == NULL)
  {
    printf("List is empty\n");
    return -1;
  }
  struct node *t = head;
  int min = head->data;
  while (t != NULL)
  {
    if (t->data < min)
    {
      min = t->data;
    }
    t = t->next;
  }
  return min;
}

void displayList()
{
  struct node *current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main()
{
  int choice, key, pos;
  printf("1.insert first 2.insert last 3.insert at\n");
  printf("4.delete first 5.delete last 6.delete at 7.delete occurrence\n");
  printf("8.search 9.find max 10.find min 11.exit\n");
  while (1)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
      // insert first
      printf("Enter element: ");
      scanf("%d", &key);
      insertBeginning(key);
    }
    else if (choice == 2)
    {
      // insert last
      printf("Enter element: ");
      scanf("%d", &key);
      insertLast(key);
    }
    else if (choice == 3)
    {
      // insert at
      printf("Enter position: ");
      scanf("%d", &pos);
      printf("Enter element: ");
      scanf("%d", &key);
      insertAt(pos, key);
    }
    else if (choice == 4)
    {
      // delete first
      deleteFirst();
    }
    else if (choice == 5)
    {
      // delete last
      deleteLast();
    }
    else if (choice == 6)
    {
      // delete at
      printf("Enter position: ");
      scanf("%d", &pos);
      deleteAt(pos);
    }
    else if (choice == 7)
    {
      // delete occurrence
      printf("Enter element: ");
      scanf("%d", &key);
      deleteOccurrences(key);
    }
    else if (choice == 8)
    {
      // search
      printf("Enter element: ");
      scanf("%d", &key);
      int idx = search(key);
      if (idx == -1)
      {
        printf("%d is not in the list.\n", key);
      }
      else
      {
        printf("The key is found at: %d\n", idx);
      }
    }
    else if (choice == 9)
    {
      int max = findMax();
      printf("The maximum element is: %d\n", max);
    }
    else if (choice == 10)
    {
      int min = findMin();
      printf("The minimum element is: %d\n", min);
    }
    else
    {
      break;
    }
    displayList();
  }
  return 0;
}
