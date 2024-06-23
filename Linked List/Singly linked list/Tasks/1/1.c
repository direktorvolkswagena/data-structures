/*
Write a program in C to create and display a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

Data entered in the list :
Data = 5
Data = 6
Data = 7
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node;

void append(node** head, int val);
node* get_node(int val);
void print(node* head);

int main()
{
  node* head = NULL;

  int num;
  printf("Input the number of nodes : ");
  scanf("%d", &num);

  for(int i = 1; i < num + 1; i++)
  {
    int val;
    printf("Input data for node %d : ", i);
    scanf("%d", &val);
    append(&head, val);
  }

  print(head);

  return 0;
}


void append(node** head, int val)
{
  node* new_node = get_node(val);

  if(*head == NULL)
    *head = new_node;
  else
  {
    node *last = *head;

    while(last -> next != NULL)
      last = last -> next;

    last -> next = new_node;
  }
}


node* get_node(int val)
{
  node* new_node = malloc(sizeof(node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}


void print(node* head)
{
  if(head == NULL)
    return;
  printf("Data = %d \n", head -> data);
  print(head -> next);
}
