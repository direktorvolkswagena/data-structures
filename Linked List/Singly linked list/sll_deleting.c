#include <stdio.h>
#include <stdlib.h>


struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node node;

void print(node **head);

void delete_beg(node **head);
void delete_last(node *head);
void delete_at_pos(node **head, int pos);
void delete_all(node **head);

int main()
{
  node *head = malloc(sizeof(node));
  head -> data = 45;
  head -> next = NULL;

  node *ptr = malloc(sizeof(node));
  ptr -> data = 98;
  ptr -> next = NULL;
  head -> next = ptr;

  ptr = malloc(sizeof(node));
  ptr -> data = 3;
  ptr -> next = NULL;
  head -> next -> next = ptr;

  //delete_beg(&head);
  //delete_last(head);
  //delete_at_pos(&head, 4);

  delete_all(&head);

  print(&head);

  return 0;
}


void delete_beg(node **head)
{
  if(*head == NULL)
  {
    printf("List is empty!\n");
    return;
  }

  node *temp = *head;
  *head = (*head) -> next;

  free(temp);
  temp = NULL;
}


void delete_last(node *head)
{
    if(head == NULL)
      printf("List is empty!\n");
    else
    {
      node *temp = NULL;
      while(head -> next != NULL)
      {
        temp = head;
        head = head -> next;
      }

      free(head);
      head = NULL;
      temp -> next = NULL;
    }
}


void delete_at_pos(node **head, int pos) // AKA pop
{
  node *current = *head;
  node *previous = *head;

  if(*head == NULL)
    printf("List is empty\n");
  else if(pos == 1)
  {
    *head = current -> next;
    free(current);
    current = NULL;
  }
  else
  {
    while(pos != 1)
    {
      previous = current;
      current = current -> next;
      pos--;

      if (current == NULL)
      {
        printf("Position out of range!\n");
        return;
      }
    }

    previous -> next = current -> next;
    free(current);
    current = NULL;
  }
}


void delete_all(node **head) // AKA wipe
{
  node *temp = *head;

  while(temp != NULL)
  {
    temp = temp -> next;
    free(*head);
    *head = temp;
  }

  *head = NULL;
  temp = NULL;

  printf("List deleted succesfully!\n");
}


void print(node **head)
{
  if(*head == NULL)
    printf("List is empty!\n");
  else
  {
    while(*head != NULL)
    {
      printf("%d ", (*head) -> data);
      (*head) = (*head) -> next;
    }
  }
}
