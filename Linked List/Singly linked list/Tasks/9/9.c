/*
Write a program in C to delete the last node of a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 1
Input data for node 2 : 2
Input data for node 3 : 3
Expected Output :

 Data entered in the list are :
 Data = 1
 Data = 2
 Data = 3

 The new list after deletion the last node are  :
 Data = 1
 Data = 2

*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* next;
};

typedef struct node Node;

Node* get_node(int val);
void append(Node** head, int val);
void del_last(Node* head);
void print(Node* head);

int main()
{
  Node* head = NULL;

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

  del_last(head);
  printf("\nThe new list after deletion the last node are :\n");
  print(head);

  return 0;
}

Node* get_node(int val)
{
  Node* new_node = malloc(sizeof(Node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

void append(Node** head, int val)
{
  Node* new_node = get_node(val);

  if(*head == NULL)
  {
    *head = new_node;
    return;
  }

  Node* last = *head;

  while(last -> next != NULL)
    last = last -> next;

  last -> next = new_node;
}

void del_last(Node* head)
{
  if(head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  Node* temp = NULL;

  while(head -> next != NULL)
  {
    temp = head;
    head = head -> next;
  }

  free(head);
  head = NULL;
  temp -> next = NULL;
}

void print(Node* head)
{
  if(head == NULL) return;
  printf("Data = %d\n", head -> data);
  print(head -> next);
}
