#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void print(node *head);

void add_at_end(node **head, int val);

int main()
{
  node *head = malloc(sizeof(node));
  head -> data = 45;
  head -> next = NULL;

  add_at_end(&head, 98);
  add_at_end(&head, 3);

  print(head);

  return 0;
}


void add_at_end(node **head, int val)
{
  node *new_node = malloc(sizeof(node));
  new_node -> data = val;
  new_node -> next = NULL;

  if(*head == NULL)
    *head = new_node; //case if list is empty
  else
  {
    node *last_node = *head;

    while (last_node -> next != NULL) last_node = last_node -> next;

    last_node -> next = new_node;
  }
}


void print(node *head)
{
  node *ptr = head;

  while(ptr != NULL)
  {
    printf("%d ", ptr -> data);
    ptr = ptr -> next;
  }
}
