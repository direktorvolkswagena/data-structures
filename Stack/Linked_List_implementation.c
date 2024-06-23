#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
  int data;
  struct node* next;
} *top = NULL;

typedef struct node Node;

Node* get_node(int val)
{
  Node* new_node = malloc(sizeof(Node));

  if (new_node == NULL)
  {
    printf("\nStack overflow! Memory allocation failed!\n");
    exit(1);
  }

  new_node -> data = val;
  new_node -> next = NULL;
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
  if(isEmpty())
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  Node* temp = top;
  int val = temp -> data;
  top = top -> next;
  free(temp);
  temp = NULL;

  return val;
}

int peek()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    exit(1);
  }

  return top -> data;
}

void print()
{
  if(isEmpty())
  {
    printf("Stack underflow!\n");
    exit(1);
  }

  Node* temp = top;

  printf("\nStack elements: \n");

  while(temp)
  {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }

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
