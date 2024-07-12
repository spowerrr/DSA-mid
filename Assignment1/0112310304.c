
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
    printf("invalid position\n");
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
    {     printf("Position exceeds the length of the list. %d is not inserted.\n",
             x);
    }
  }
}

void deleteFirst()
{
  if (head == NULL)
  {
    printf("List is empty");
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
  if (pos == 1)
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
    printf("Position exceeds the length of the list");
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
    printf("List is empty");
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
    printf("List is empty");
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
  printf("4.delete first 5.delete last 6.delete at "
         "7.search 8.find max 9.find min 10.exit\n");
  while (1)
  {

    printf("enter choice:");
    scanf("%d", &choice);
    if (choice == 1)
    {
      // complete the code
      // for insert first
      printf("enter element: ");
      scanf("%d", &key);
      insertBeginning(key);
    }
    else if (choice == 2)
    {
      // insert last
      printf("enter element: ");
      scanf("%d", &key);
      insertLast(key);
    }
    else if (choice == 3)
    {
      // insert at
      printf("enter position:");
      scanf("%d", &pos);
      printf("enter element:");
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
      printf("enter position:");
      scanf("%d", &pos);
      deleteAt(pos);
    }
    else if (choice == 7)
    {
      // search
      printf("enter element:");
      scanf("%d", &key);
      int idx = search(key);
      if (idx == -1)
      {
        printf("%d is not in the list.\n", key);
      }
      else
      {
        printf("The key is found at:%d\n", idx);
      }
    }
    else if (choice == 8)
    {
      int max = findMax();
      printf("The maximum element is:%d\n", max);
    }
    else if (choice == 9)
    {
      int min = findMin();
      printf("The minimum element is:%d\n", min);
    }
    else
    {
      break;
    }
    displayList();
  }
}
