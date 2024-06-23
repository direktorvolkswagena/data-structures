#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"


Node *get_node(int val)
{
  Node *new_node = malloc(sizeof(Node));

  if (new_node == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}


void list_push(Node **head, int val)
{
  Node *new_node = get_node(val);
  new_node -> next = *head;
  *head = new_node;
}


void list_append(Node **head, int val)
{
  Node *new_node = get_node(val);

  if(*head == NULL)
      *head = new_node;
  else
  {
    Node *last_node = *head;

    while(last_node -> next != NULL)
      last_node = last_node -> next;

    last_node -> next = new_node;
  }
}


void list_insert(Node **head, int val, int pos)
{
  if(pos < 1)
  {
    printf("Invalid position\n");
    return;
  }
  else
  {
    Node *new_node = get_node(val);

    if(pos == 1)
    {
      new_node -> next = *head;
      *head = new_node;
      return;
    }

    Node *current = *head;

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


void list_del_beg(Node **head)
{
  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    Node *temp = (*head) -> next;
    free(*head);
    *head = temp;
    temp = NULL;
  }
}


void list_del_end(Node *head)
{
  if(head == NULL)
  {
    printf("List is empty!\n");
    return;
  }
  else
  {
    Node *temp = NULL;
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


void list_pop(Node **head, int pos)
{
  Node *current = *head;
  Node *previous = *head;

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


void list_wipe(Node **head)
{
  Node *temp = *head;

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


void lsit_reverse(Node **head)
{
  Node *prev = NULL;
  Node *next = NULL;

  while(*head != NULL)
  {
    next = (*head) -> next;
    (*head) -> next = prev;
    prev = *head;
    *head = next;
  }
  *head = prev;
}


void list_display(Node *head)
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


void list_display_reversed(Node *head)
{
  if(head == NULL) return;
  list_display_reversed(head -> next);
  printf("%d ", head -> data);
}
