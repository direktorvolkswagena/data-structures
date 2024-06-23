#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void add_beg(node **head, int val);

void print(node *head);

int main()
{
  node *head = malloc(sizeof(node));
  head -> data = 45;
  head -> next = NULL;

  node *ptr = malloc(sizeof(node));
  ptr -> data = 98;
  ptr -> next = NULL;

  head -> next = ptr;

  add_beg(&head, 15);

  print(head);

  return 0;
}


void add_beg(node **head, int val)
{
  node *ptr = malloc(sizeof(node));
  ptr -> data = val;
  ptr -> next = *head;

  *head = ptr;
}

void print(node *head)
{
  while(head != NULL)
  {
    printf("%d ", head -> data);
    head = head -> next;
  }
}
