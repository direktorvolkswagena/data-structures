/*
Write a program in C to insert a node in the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes (3 or more) : 4
 Input data for node 1 : 1
 Input data for node 2 : 2
 Input data for node 3 : 3
 Input data for node 4 : 4

 Data entered in the list are :
 Data = 1
 Data = 2
 Data = 3
 Data = 4

 Input data to insert in the middle of the list : 5
 Input the position to insert new node : 3

 Insertion completed successfully.

 The new list are :
 Data = 1
 Data = 2
 Data = 5
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
void append(node** head, int val);
void insert(node** head, int val, int pos);
void print(node* head);

int main()
{
  node* head = NULL;

  int n;
  printf("Input the number of nodes (3 or more) : ");
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

  int val1, pos;
  printf("\nInput data to insert in the middle of the list : ");
  scanf("%d", &val1);

  printf("\nInput the position to insert new node : ");
  scanf("%d", &pos);

  insert(&head, val1, pos);

  printf("The new list are :\n");
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

void insert(node** head, int val, int pos)
{
  if(pos < 1)
  {
    printf("Invalid position!\n");
    return;
  }

  node* new_node = get_node(val);

  if(pos == 1)
  {
    new_node -> next = *head;
    *head = new_node;
    return;
  }

  node* current = *head;

  pos--;
  while(pos != 1 && current != NULL)
  {
    current = current -> next;
    pos--;

    if(current == NULL)
    {
      printf("Invalid position!\n");
      return;
    }
  }

  new_node -> next = current -> next;
  current -> next = new_node;

  printf("Insertion completed successfully!");
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
