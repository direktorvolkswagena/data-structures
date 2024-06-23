#include<stdio.h>
#include<stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

int main(void)
{
  node *head = NULL;
  head = (node*)malloc(sizeof(node)); // typecasting is not mandatory

  head -> data = 45;
  head -> next = NULL;

  printf("%d", head -> data);

  return 0;
}
