#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node node;

void push(node** head, int val);
node* get_node(int val);
void print(node* head);

int main()
{
  node* head = NULL;

  push(&head, 12);
  push(&head, 31);

  print(head);

  return 0;
}


void push(node** head, int val)
{
  node* new_node = get_node(val);

  if(*head == NULL) *head = new_node;
  else
  {
    new_node -> next = *head;
    (*head) -> prev = new_node;
    *head = new_node;
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
