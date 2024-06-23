#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

int main(void)
{
  node *head = malloc(sizeof(node));
  head -> data = 45;
  head -> next = NULL;

  node *current = malloc(sizeof(node));
  current -> data = 98;
  current -> next = NULL;
  head -> next = current;

  return 0;
}
