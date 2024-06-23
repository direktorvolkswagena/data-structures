#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void rec_print(node *head);
void rev_rec_print(node *head);

int main()
{
  node *head = malloc(sizeof(node));
  head -> data = 2;
  head -> next = NULL;

  node *ptr = malloc(sizeof(node));
  ptr -> data = 6;
  ptr -> next = NULL;
  head -> next = ptr;

  node *ptr2 = malloc(sizeof(node));
  ptr2 -> data = 5;
  ptr2 -> next = NULL;
  ptr -> next = ptr2;

  rec_print(head);
  printf("\n");
  rev_rec_print(head);
}


void rec_print(node *head)
{
  if(head == NULL) return;
  printf("%d ", head -> data);
  rec_print(head -> next);
}


void rev_rec_print(node *head)
{
  if(head == NULL) return;
  rev_rec_print(head -> next);
  printf("%d ", head -> data);
}
