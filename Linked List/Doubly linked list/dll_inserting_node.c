#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
  struct Node* prev;
};

typedef struct Node node;

node* get_node(int val);

int main()
{
  node* head = NULL;
  head = get_node(45);
  printf("%d", head -> data);
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
