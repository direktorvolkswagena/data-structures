#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node;

void add_end(node **head, int val);
void add_beg(node **head, int val);
void add_at_pos(node **head, int val, int pos);

node *get_node(int val);
void print(node *head);

int main()
{
  node *head = NULL;

  add_end(&head, 45);
  add_end(&head, 98);
  add_end(&head, 3);

  add_beg(&head, 15);

  add_at_pos(&head, 23, 3);

  print(head);

  return 0;
}


void add_end(node **head, int val) // AKA append
{
  node *new_node = get_node(val);

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


void add_beg(node **head, int val) // AKA push
{
  node *new_node = get_node(val);

  new_node -> next = *head;

  *head = new_node;
}


void add_at_pos(node **head, int val, int pos) // AKA insert
{
  if (pos < 1)
    printf("Invalid position!\n");
  else
  {
    node *new_node = get_node(val);

    if(pos == 1)
    {
      new_node -> next = *head;
      *head = new_node;
      return;
    }

    node *current = *head;

    pos--;
    while(pos != 1 && current != NULL)
    {
      current = current -> next;
      pos--;

      if (current == NULL)
      {
        printf("Position out of range!\n");
        return;
      }
    }

    new_node -> next = current -> next;
    current -> next = new_node;
  }
}


node *get_node(int val)
{
  node *new_node = malloc(sizeof(node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
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
