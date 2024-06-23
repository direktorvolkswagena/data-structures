#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5 // Maximum capacity of stack, must be changed manually

int stack_arr[MAX];
int top = -1;

bool isFull()
{
  return top == MAX - 1;
}

bool isEmpty()
{
  return top == -1;
}

void push(int data)
{
  if(isFull())
  {
    printf("Stack overflow!\n");
    return;
  }
  top++;
  stack_arr[top] = data;
}

int pop()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    exit(1);
  }
  int val = stack_arr[top];
  top--;

  return val;
}

int peek()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    exit(1);
  }
  return stack_arr[top];
}

void print()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    return;
  }

  printf("\nStack is: \n");

  for(int i = top; i >= 0; i--)
    printf("%d\n", stack_arr[i]);

  printf("\n");
}

int main()
{
  int choice;

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
        int qty;
        printf("\nHow many elements would you like to push? : ");
        scanf("%d", &qty);

        if(qty > MAX)
        {
          printf("\nInvalid quantity, risk of stack overflow!\n");
          exit(1);
        }
        while(qty > 0)
        {
          int val;
          printf("Enter the element to be pushed: ");
          scanf("%d", &val);
          push(val);
          qty--;
        }

        printf("\nDone succesfully!\n\n");

        break;

      case 2:
        int data = pop();
        printf("\nPopped element: %d\n\n", data);
        break;

      case 3:
        int p = peek();
        printf("\nTop element: %d\n\n", p);
        break;

      case 4:
        print();
        break;

      case 5:
        exit(1);

      default:
        printf("\nInvalid input! try again!\n\n");
    }
  }

  return 0;
}
