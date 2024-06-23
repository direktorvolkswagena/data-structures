/*
Write a C program to implement a stack using an array with push and pop operations.
Expected Output:
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 7

int stack[MAX];
int top = -1;

void push(int data);
int pop();
void print();

int main()
{
  push(12);
  push(15);
  push(75);
  push(89);

  pop();

  print();

  return 0;
}

void push(int data)
{
  if(top == MAX - 1)
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
