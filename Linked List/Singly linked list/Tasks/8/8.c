/*
Write a program in C to delete a node from the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
 Input data for node 1 : 2
 Input data for node 2 : 5
 Input data for node 3 : 8

 Data entered in the list are :
 Data = 2
 Data = 5
 Data = 8

 Input the position of node to delete : 2

 Deletion completed successfully.

 The new list are  :
 Data = 2
 Data = 8
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node;

node* get_node(int val);
void append(node** head, int val);
void pop(node** head, int pos);
void print(node* head);

int main()
{
  node* head = NULL;

  int n;
  printf("\nInput the number of nodes : ");
  scanf("%d", &n);

  for(int i = 1; i <= n; i++)
  {
    int val;
    printf("Input data for node %d : ", i);
    scanf("%d", &val);
    append(&head, val);
  }

  printf("\nData entered in the list are : \n");
  print(head);

  int pos;
  printf("\nInput the position of node to delete : ");
  scanf("%d", &pos);

  pop(&head, pos);

  printf("\nThe new list are:\n");
  print(head);

  return 0;
}

node* get_node(int val)
{
  node* new_node = malloc(sizeof(node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

void append(node** head, int val)
{
  node* new_node = get_node(val);

  if(*head == NULL)
  {
    *head = new_node;
    return;
  }

  node* last = *head;

  while(last -> next != NULL)
    last = last -> next;

  last -> next = new_node;
}

void pop(node** head, int pos)
{
  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  if(pos < 1)
  {
    printf("Invalid position!\n");
    return;
  }

  node* current = *head;
  node* previous = *head;

  if(pos == 1)
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
        printf("Invalis position!\n");
        return;
      }

    }
      previous -> next = current -> next;
      free(current);
      current = NULL;
  }

  printf("\nDeletion completed successfully!\n");
}

void print(node* head)
{
  if(head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  while(head != NULL)
  {
    printf("Data = %d\n", head -> data);
    head = head -> next;
  }
}
