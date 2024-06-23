/*
Write a C program that converts a singly linked list into an array and returns it.
Test Data and Expected Output :


Linked List: Convert a Singly Linked list into a string
-------------------------------------------------------------
Input the number of nodes: 3
 Input data for node 1 : 10
 Input data for node 2 : 20
 Input data for node 3 : 30

Return data entered in the list as a string:
The linked list: 10 20 30
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* next;
};

typedef struct node Node;

int* list_to_arr(Node* head, int size);
Node* get_node(int val);
void append(Node** head, int val);
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

  int* arr = list_to_arr(head, n);
  printf("\nThe linked list: ");

  for(int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");

  return 0;
}

int* list_to_arr(Node* head, int size)
{
  int* arr = malloc(sizeof(int) * size);

  Node* current = head;

  int i = 0;
  while(current != NULL)
  {
    arr[i++] = current -> data; // post increment!
    current = current -> next;
  }

  return arr;
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

  Node* current = *head;

  while(current -> next != NULL)
    current = current -> next;

  current -> next = new_node;
}

void print(Node* head)
{
  if(head == NULL) return;
  printf("Data = %d\n", head -> data);
  print(head -> next);
}
