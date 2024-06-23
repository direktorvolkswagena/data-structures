#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *data;
  int top;
  int size;
} Stack;

void init(Stack *stack, int size);
void push(Stack *stack, int val);
int pop(Stack *stack);
void print(Stack *stack);
void reverse(Stack *stack);

int main()
{
  Stack original;
  int size = 5;
  init(&original, size);
  push(&original, 12);
  push(&original, 13);
  push(&original, 15);
  push(&original, 16);
  push(&original, 21);

  print(&original);

  reverse(&original);

  print(&original);

  return 0;
}

void init(Stack *stack, int size)
{
  stack -> data = malloc(size * sizeof(int));
  stack -> top = -1;
  stack -> size = size;
}

void push(Stack *stack, int val)
{
  if(stack -> top == stack -> size - 1)
  {
    printf("\nStack overflow!\n\n");
    return;
  }

  stack -> data[++stack -> top] = val;
}

int pop(Stack *stack)
{
  if(stack -> top == -1)
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top--];
}

void print(Stack *stack)
{
  if(stack -> top == -1)
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  printf("\nStack elements: \n");

  for(int i = stack -> top; i >= 0; i--)
    printf("%d\n", stack -> data[i]);

  printf("\n");
}

void reverse(Stack *stack)
{
  Stack temp1, temp2;
  int size = stack -> size;
  init(&temp1, size);
  init(&temp2, size);

  int i = 0;
  do {
    push(&temp1, pop(stack));
    i++;
  } while(i < size);

  i = 0;
  do {
    push(&temp2, pop(&temp1));
    i++;
  } while(i < size);

  i = 0;
  do {
    push(stack, pop(&temp2));
    i++;
  } while(i < size);
}
