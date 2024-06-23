#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node;

void append(node **head, int val);
void reverse(node **head);
void print(node *head);

int main()
{
  node *head = NULL;
  append(&head, 45);
  append(&head, 98);
  append(&head, 3);
  append(&head, 5);

  printf("Given linked list\n");
  print(head);

  reverse(&head);

  printf("\nReversed linked list: \n");
  print(head);

  return 0;
}


void append(node **head, int val)
{
  node *new_node = malloc(sizeof(node));
  new_node -> data = val;
  new_node -> next = NULL;

  if(*head == NULL)
    *head = new_node;
  else
  {
    node *last_node = *head;

    while(last_node -> next != NULL)
      last_node = last_node -> next;

    last_node -> next = new_node;
  }
}


void reverse(node **head)
{
  node *prev = NULL;
  node *next = NULL;

  while(*head != NULL)
  {
    next = (*head) -> next;
    (*head) -> next = prev;
    prev = *head;
    *head = next;
  }
  *head = prev;
}


void print(node *head)
{
  if(head == NULL)
    printf("List is empty!\n");
  else
  {
    while(head != NULL)
      {
        printf("%d ", head -> data);
        head = head -> next;
      }
  }
}
