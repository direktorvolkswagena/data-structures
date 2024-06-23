/*
Write a program in C to search for an existing element in a singly linked list.
Test Data and Expected Output :

Input the number of nodes : 3

Input data for node 1 : 2
Input data for node 2 : 5
Input data for node 3 : 8

Data entered in the list are :
Data = 2
Data = 5
Data = 8

Input the element to be searched : 5
Element found at node 2
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
int find(Node* head, int val);
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

  int val1;
  printf("\nInput the element to be searched : ");
  scanf("%d", &val1);

  int res = find(head, val1);

  if(res)
    printf("Element found at node %d\n", res);

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

int find(Node* head, int val)
{
  int count = 1;

  while(head -> data != val)
  {
    if(head -> next == NULL)
    {
      printf("Element has not been found!\n");
      return 0;
    }
    count++;
    head = head -> next;
  }

  return count;
}

void print(Node* head)
{
  if(head == NULL) return;
  printf("Data = %d\n", head -> data);
  print(head -> next);
}
