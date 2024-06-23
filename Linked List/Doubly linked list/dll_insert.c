#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node node;

node *get_node(int val);
void print(node *head);

int main()
{
  node* head = NULL;

  head = get_node(43);

  print(head);
  
  return 0;
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
