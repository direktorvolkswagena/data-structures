/*
Write a program in C to create a singly linked list of n nodes and count the
number of nodes.

Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7

Expected Output :
Data entered in the list are :
Data = 5
Data = 6
Data = 7
Total number of nodes = 3
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
void print(node* head);
int node_count(node* head);

int main()
{
  node* head = NULL;

  int num;
  printf("Input the number of nodes : ");
  scanf("%d", &num);

  for(int i = 1; i <= num; i++)
  {
    int val;
    printf("Input data for node %d : ", i);
    scanf("%d", &val);
    append(&head, val);
  }

  printf("\nData entered in the list are :\n");
  print(head);

  printf("\nTotal number of nodes = %d\n", node_count(head));

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
    *head = new_node;
  else
  {
    node* last = *head;

    while(last -> next != NULL)
      last = last -> next;

    last -> next = new_node;
  }
}


void print(node* head)
{
  if(head == NULL)
    return;
  printf("Data = %d\n", head -> data);
  print(head -> next);
}


int node_count(node* head)
{
  int count = 0;

  while(head != NULL)
  {
    count++;
    head = head -> next;
  }

  return count;
}
