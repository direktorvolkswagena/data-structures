#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void print_data(node *head);

int main(void)
{
  node *head = malloc(sizeof(node));
  //head = NULL;
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

  print_data(head);

  return 0;
}


void print_data(node *head)
{
    if(head == NULL) printf("List is empty");
    else
    {
      node *ptr = head;

      while(ptr != NULL)
      {
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
      }
    }
}
