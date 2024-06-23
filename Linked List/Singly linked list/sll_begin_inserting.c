#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

node *add_beg(node *head, int val);

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

  int data = 3;

  head = add_beg(head, data);
  ptr = head;

  print(head);

  return 0;
}


node *add_beg(node *head, int val)
{
    node *ptr = malloc(sizeof(node));
    ptr -> data = val;
    ptr -> next = head;
    head = ptr;

    return head;
}


void print(node *head)
{
  node *temp = head;

  while (temp != NULL)
  {
    printf("%d ", temp -> data);
    temp = temp -> next;
  }
}
