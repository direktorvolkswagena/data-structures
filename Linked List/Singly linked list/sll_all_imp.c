#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

//Crating node
node *get_node(int val);
// Adding nodes
void push(node **head, int val);
void append(node **head, int val);
void insert(node **head, int val, int pos);
//Deleting nodes
void del_beg(node **head);
void del_end(node *head);
void pop(node **head, int pos);
void wipe(node **head);
//Reversing list
void reverse(node **head);
//Printing node
void print(node *head);
void print_rec(node *head);
void print_rev_rec(node *head);

int main()
{
  node *head = NULL;

  // push(&head, 3);
  // push(&head, 45);
  // push(&head, 228);
  //
  // append(&head, 15);
  //
  // insert(&head, 9, 3);
  //
  // del_end(head);
  //
  // pop(&head, 3);
  //
  // wipe(&head);
  //
  // reverse(&head);

  // print(head);
  // print_rec(head);
  // print_rev_rec(head);

  return 0;
}


node *get_node(int val)
{
  node *new_node = malloc(sizeof(node));

  if (new_node == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}


void push(node **head, int val)
{
  node *new_node = get_node(val);
  new_node -> next = *head;
  *head = new_node;
}


void append(node **head, int val)
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


void insert(node **head, int val, int pos)
{
  if(pos < 1)
  {
    printf("Invalid position\n");
    return;
  }
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

      if(current == NULL)
      {
        printf("Invalid position\n");
        return;
      }
    }

    new_node -> next = current -> next;
    current -> next = new_node;
  }
}


void del_beg(node **head)
{
  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    node *temp = (*head) -> next;
    free(*head);
    *head = temp;
    temp = NULL;
  }
}


void del_end(node *head)
{
  if(head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    node *temp = NULL;
    while(head -> next != NULL)
    {
      temp = head;
      head = head -> next;
    }

    free(head);
    head = NULL;
    temp -> next = NULL;
  }
}


void pop(node **head, int pos)
{
  node *current = *head;
  node *previous = *head;

  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else if(pos < 1)
  {
    printf("Invalid position!\n");
    return;
  }
  else if(pos == 1)
  {
    *head = current -> next;
    free(current);
    current = NULL;
  }
  else
  {
    while(pos != 1)
    {
      previous = current;
      current = current -> next;
      pos--;

      if(current == NULL)
      {
        printf("Invalid position!\n");
        return;
      }
    }

    previous -> next = current -> next;
    free(current);
    current = NULL;
  }
}


void wipe(node **head)
{
  node *temp = *head;

  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    while(temp != NULL)
    {
      temp = temp -> next;
      free(*head);
      *head = temp;
    }
  }

  *head = NULL;
  temp = NULL;

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
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    while(head != NULL)
    {
      printf("%d ", head -> data);
      head = head -> next;
    }
  }
}


void print_rec(node *head)
{
  if(head == NULL) return;
  printf("%d ", head -> data);
  print_rec(head -> next);
}


void print_rev_rec(node *head)
{
  if(head == NULL) return;
  print_rev_rec(head -> next);
  printf("%d ", head -> data);
}
