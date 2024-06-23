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
void destroy(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack, int val);
int pop(Stack *stack);
int peek(Stack *stack);
void print(Stack *stack);


int main()
{
  Stack stack;
  int choice, size = 4;
  init(&stack, size);

  while(1)
  {
    printf("Stack menu: \n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display top element\n");
    printf("4. Display all elements\n");
    printf("5. Quit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
      case 1:
        int qty = size;

        while(qty > 0)
        {
          int val;
          printf("Enter the element to be pushed: ");
          scanf("%d", &val);
          push(&stack, val);
          qty--;
        }

        printf("\nDone succesfully!\n\n");

        break;

      case 2:
        int data = pop(&stack);
        printf("\nPopped element: %d\n\n", data);
        break;

      case 3:
        int p = peek(&stack);
        printf("\nTop element: %d\n\n", p);
        break;

      case 4:
        print(&stack);
        break;

      case 5:
        exit(1);

      default:
        printf("\nInvalid input! try again!\n\n");
    }
  }

  destroy(&stack);

  return 0;
}


void init(Stack *stack, int size)
{
  stack -> data = malloc(size * sizeof(int));
  stack -> top = -1;
  stack -> size = size;
}

void destroy(Stack *stack)
{
  free(stack -> data);
}

bool isFull(Stack *stack)
{
  return stack -> top == stack -> size - 1;
}

bool isEmpty(Stack *stack)
{
  return stack -> top == -1;
}

void push(Stack *stack, int val)
{
  if(isFull(stack))
  {
    printf("\nStack overflow!\n\n");
    return;
  }

  stack -> data[++stack -> top] = val; // Post incrementation
}

int pop(Stack *stack)
{
  if(isEmpty(stack))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  return stack -> data[stack -> top--]; //post decrement!!
}

int peek(Stack *stack)
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

  printf("\nStack elements: \n");

  for(int i = stack -> top; i >= 0; i--)
    printf("%d\n", stack -> data[i]);

  printf("\n");
}
