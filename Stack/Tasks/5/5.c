/*
Write a C program to implement two stacks in a single array and perform push
and pop operations for both stacks.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500

int stack[MAX_SIZE];
int top_1 = -1;
int top_2 = MAX_SIZE;


void push_1(int val);
int pop_1();

void push_2(int val);
int pop_2();


int main()
{
  push_1(15);
  push_1(25);
  pop_1();
  push_1(76);
  push_1(34);

  push_2(13);
  push_2(203);
  push_2(1234);
  push_2(1345);
  pop_2();
  pop_2();
  push_2(132453);

  printf("Elements in Stack 1 are:\n");
  while(top_1 != -1)
  {
    printf("%d\n", pop_1());
  }
  printf("\n");

  printf("Elements in Stack 2 are:\n");
  while(top_2 != MAX_SIZE)
  {
    printf("%d\n", pop_2());
  }
  printf("\n");

  return 0;
}


void push_1(int val)
{
  if(top_1 == top_2 - 1)
  {
    printf("Stack 1 overflow!\n");
    return;
  }

  top_1++;
  stack[top_1] = val;
}

int pop_1()
{
  if(top_1 == -1)
  {
    printf("Stack_1 is empty!\n");
    return -1;
  }

  int val = stack[top_1];
  top_1--;

  return val;
}

void push_2(int val)
{
  if(top_2 == top_1 + 1)
  {
    printf("Stack 2 overflow!\n");
    return;
  }

  top_2--;
  stack[top_2] = val;
}

int pop_2()
{
  if(top_2 == MAX_SIZE)
  {
    printf("Stack_2 is empty!\n");
    return -1;
  }

  int val = stack[top_2];
  top_2++;

  return val;
}
