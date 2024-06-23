/*
Write a program in C to insert a new node at the end of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7

Data entered in the list are :
Data = 5
Data = 6
Data = 7

Input data to insert at the end of the list : 8

Data, after inserted in the list are :
Data = 5
Data = 6
Data = 7
Data = 8
*/


#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node* next;
};

typedef struct Node node;

node* get_node(int val);
void print(node* head);
void append(node** head, int val);

int main()
{
  node* head = NULL;

  int n;
  printf("Input the number of nodes : ");
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

  int val1;
  printf("\nInput data to insert at the end of the list : ");
  scanf("%d", &val1);
  append(&head, val1);

  printf("\nData, after inserted in the list are : \n");
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
