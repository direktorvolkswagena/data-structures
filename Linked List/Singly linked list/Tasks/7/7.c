/*
Write a program in C to delete the first node of a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 2
Input data for node 2 : 3
Input data for node 3 : 4
Expected Output :

 Data entered in the list are :
 Data = 2
 Data = 3
 Data = 4

 Data of node 1 which is being deleted is :  2

 Data, after deletion of first node :
 Data = 3
 Data = 4
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
void print(node* head);
void append(node** head, int val);
void del_beg(node** head);

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

  printf("\nData of node 1 which is being deleted is : %d\n", head -> data);

  del_beg(&head);

  printf("Data, after deletion of first node : \n");
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

void del_beg(node** head)
{
  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  node* temp = (*head) -> next;
  free(*head);
  *head = temp;
  temp = NULL;
}
