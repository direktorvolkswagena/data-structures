#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


void stack_init(Stack *stack, int size)
{
  stack -> data = malloc(size * sizeof(char));
  stack -> top = -1;
  stack -> size = size;
}


void stack_destroy(Stack *stack)
{
  free(stack -> data);
}


bool stack_isFull(Stack *stack)
{
  return stack -> top == stack -> size - 1;
}


bool stack_isEmpty(Stack *stack)
{
  return stack -> top == -1;
}


void stack_push(Stack *stack, char val)
{
  if(stack_isFull(stack))
  {
    printf("\nStack overflow!\n\n");
    return;
  }

  stack -> data[++stack -> top] = val;
}


char stack_pop(Stack *stack)
{
  if(stack_isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top--];
}


char stack_peek(Stack *stack)
{
  if(stack_isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top];
}


void stack_display(Stack *stack)
{
  if(stack_isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    return;
  }

  printf("\nStack elements: \n");

  for(int i = stack -> top; i >= 0; i--)
    printf("%c\n", stack -> data[i]);

  printf("\n");
}
