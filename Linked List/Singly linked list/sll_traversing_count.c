// Traversing is visinting each node of single linked list list until the end node is reached

#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void count_of_nodes(node *head);

int main(void)
{
  node *head = malloc(sizeof(node));
  head -> data = 45;
  head -> next = NULL;

  node *current = malloc(sizeof(node));
  current -> data = 98;
  current -> next = NULL;
  head -> next = current;

  current = malloc(sizeof(node));
  current -> data = 3;
  current -> next = NULL;
  head -> next -> next = current;

  count_of_nodes(head);

  return 0;
}


void count_of_nodes(node *head)
{
  int count = 0;

  if(head == NULL) printf("List is empty");
  else
  {
    node *ptr = head;

    while(ptr != NULL)
    {
      count++;
      ptr = ptr -> next; // acessing the link part of node we are going to visit for counting
    }

    printf("There are %d node in a given list\n", count);
  }
}
