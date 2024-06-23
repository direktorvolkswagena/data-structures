#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node node;

void append(node** head, int val);
node* get_node(int val);
void print(node* head);

int main()
{
  node* head = get_node(45);

  append(&head, 25);

  print(head);

  return 0;
}


void append(node** head, int val)
{
  node* new_node = get_node(val);

  if(*head == NULL)
    *head = new_node;
  else
  {
    node* last = *head;

    while(last -> next != NULL)
      last = last -> next;

    last -> next = new_node;
    new_node -> prev = last;
  }
}


node* get_node(int val)
{
  node* new_node = malloc(sizeof(node));

  new_node -> prev = NULL;
  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}


void print(node* head)
{
  if(head == NULL) return;
  printf("%d ", head -> data);
  print(head -> next);
}
