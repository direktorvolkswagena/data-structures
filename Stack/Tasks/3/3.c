/*
Write a C program to check a stack is full or not using an array with push and pop operations.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 7

int stack[MAX];
int top = -1;

void push(int data);
int pop();
void print();
bool isFull();

int main()
{
  push(12);
  push(15);
  push(75);
  push(89);
  push(89);

  pop();

  print();

  return 0;
}

void push(int data)
{
  if(isFull())
  {
    printf("Stack overflow!\n");
    return;
  }

  top++;
  stack[top] = data;
}

int pop()
{
  if(top == -1)
  {
    printf("Stack underflow!\n");
    exit(1);
  }

  int val = stack[top];
  top--;

  return val;
}

void print()
{
  if(top == -1)
  {
    printf("Stack underflow!\n");
    return;
  }

  printf("\nStack is: \n");

  for (int i = top; i >= 0; i--)
    printf("%d\n", stack[i]);

  printf("\n");
}

bool isFull()
{
  return top == MAX - 1;
}
