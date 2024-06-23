#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node sNode;

bool isEmpty(sNode* top);
sNode* get_node(int val);
void push(sNode** top, int val);
void print(sNode* top);
int pop(sNode **top);
void reverse(sNode **top);

int main()
{
  sNode *top = NULL;

  push(&top, 12);
  push(&top, 14);
  push(&top, 155);

  print(top);

  reverse(&top);

  print(top);

  return 0;
}

bool isEmpty(sNode* top)
{
  return top == NULL;
}

sNode* get_node(int val)
{
  sNode* new_node = malloc(sizeof(sNode));

  if(isEmpty(new_node))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

void push(sNode** top, int val)
{
  sNode* new_node = get_node(val);

  new_node -> next = *top;
  *top = new_node;
}

void print(sNode* top)
{
  if(isEmpty(top))
  {
    printf("\nStack underflow!\n\n");
    return;
  }

  sNode* temp = top;

  printf("\nStack elements are:\n");

  while(temp)
  {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }

  printf("\n");
}

int pop(sNode **top)
{
  if(isEmpty(*top))
  {
    printf("\nStack underflow!\n\n");
    exit(1);
  }

  sNode *temp = *top;
  *top = (*top) -> next;
  return temp -> data;
}

void reverse(sNode **top)
{
  sNode *top1 = NULL, *top2 = NULL;

  while(*top)
    push(&top1, pop(top));

  while(top1)
    push(&top2, pop(&top1));

  while(top2)
    push(top, pop(&top2));
}
