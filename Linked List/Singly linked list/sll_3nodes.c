#include <stdio.h>
#include <stdlib.h>


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

  /* Now we will add third node to the list
  First method:

  node *current2 = malloc(sizeof(node));
  current2 -> data = 3;
  current2 -> next = NULL:
  current -> next = current2;

  Pretty much the same as adding second one. That is not optimal, since for the
  each node we need its own pointer
  */

  current = malloc(sizeof(node));
  current -> data = 3;
  current -> next = NULL;

  head -> next -> next = current; // more effcient way, but still creates a mess

  return 0;
}
