//AKA valid parentheses

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
  char *data;
  int top;
  int size;
} Stack;

void init(Stack *stack, int size);
bool isEmpty(Stack *stack);
void push(Stack *stack, char val);
char pop(Stack *stack);
char top(Stack *stack);
void print(Stack *stack);
bool isValid(char *eq);

int main()
{
  char eq[200];

  printf("Enter equation:\n");
  fgets(eq, 200, stdin);

  size_t len = strlen(eq);
  if (len > 0 && eq[len-1] == '\n') eq[len-1] = '\0'; // In order to eliminate a space in end

  if(isValid(eq)) printf("Valid!\n");
  else printf("Invalid!\n");

  return 0;
}

void init(Stack *stack, int size)
{
  stack -> data = malloc(size * sizeof(char));
  stack -> top = -1;
  stack -> size = size;
}

bool isFull(Stack *stack)
{
  return stack -> top == stack -> size - 1;
}

bool isEmpty(Stack *stack)
{
  return stack -> top == -1;
}

void push(Stack *stack, char val)
{
  if(isFull(stack))
  {
    printf("\nStack overflow!\n\n");
    return;
  }

  stack -> data[++stack -> top] = val;
}

char pop(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top--];
}

char top(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top];
}

void print(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    return;
  }

  printf("\nStack elements: \n\n");

  for(int i = stack -> top; i >= 0; i--)
    printf("%c\n", stack -> data[i]);

  printf("\n");
}

bool isValid(char *eq)
{
  int size = strlen(eq);
  Stack stack;
  init(&stack, size);

  for(int i = 0; i < size; i++)
  {
    if(eq[i] == '(' || eq[i] == '[' || eq[i] == '{') push(&stack, eq[i]);
    else
    {
      if(isEmpty(&stack)) return false;

      char temp;
      if((eq[i] == ')' && top(&stack) == '(') ||
      (eq[i] == ']' && top(&stack) == '[') ||
      (eq[i] == '}' && top(&stack) == '{')) temp = pop(&stack);
      else return false;
    }
  }
  return stack_isEmpty(&stack);
}
