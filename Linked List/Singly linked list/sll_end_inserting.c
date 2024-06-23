#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void insert_at_end(node *head, int data);
void print_data(node *head);

int main()
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

  insert_at_end(head, 67); // Function takes two argument: head and the data for the next node
  print_data(head);

  return 0;
}


void insert_at_end(node *head, int val) // dumb implementation (works only with non empty list)
{
  node *ptr = head, *temp = malloc(sizeof(node));

  temp -> data = val;
  temp -> next = NULL;

  while(ptr -> next != NULL) ptr = ptr -> next;

  ptr -> next = temp;
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
