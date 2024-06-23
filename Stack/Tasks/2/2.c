/*
Write a C program to implement a stack using a singly linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *top = NULL;

Node* get_node(int val);
bool isEmpty();
void push(int val);
int pop();
void print();


int main()
{
  push(15);
  push(16);
  push(228);
  push(17);

  print();

  pop();
  pop();
  pop();
  pop();
  
  isEmpty() ? printf("Stack is empty!\n") : printf("Stack is not empty!\n");

  return 0;
}


Node* get_node(int val)
{
  Node* new_node = malloc(sizeof(Node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

bool isEmpty()
{
  return top == NULL;
}

void push(int val)
{
  Node* new_node = get_node(val);

  new_node -> next = top;
  top = new_node;
}

int pop()
{
  Node* temp = top;
  int val = temp -> data;
  top = top -> next;
  free(temp);
  temp = NULL;

  return val;
}

void print()
{
  Node *temp = top;

  printf("Stack is:\n");

  while(temp)
  {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }

  printf("\n");
}
