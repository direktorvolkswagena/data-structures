/*
13. Write a C program to merge two sorted singly linked lists into a single sorted linked list.
Test Data and Expected Output :

Two sorted singly linked lists:
1 3 5 7
2 4 6

After merging the said two sorted lists:
1 2 3 4 5 6 7
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node* next;
};

typedef struct node Node;

Node* merge_two_lists_r(Node* l1_head, Node* l2_head);
Node* merge_two_lists(Node* list1, Node* list2);
Node* get_node(int val);
void append(Node** head, int val);
void print(Node* head);

int main()
{
  Node* l1_head = get_node(1);
  l1_head -> next = get_node(3);
  l1_head -> next -> next = get_node(5);
  l1_head -> next -> next -> next = get_node(7);

  Node* l2_head = get_node(2);
  l2_head -> next = get_node(4);
  l2_head -> next -> next = get_node(6);

  printf("\nData entered in the lists are : \n");
  print(l1_head);
  printf("\n");
  print(l2_head);

  Node* merged = merge_two_lists(l1_head, l2_head);
  printf("\nAfter merging the said two sorted lists: \n");
  print(merged);

  return 0;
}

Node* merge_two_lists(Node* list1, Node* list2)
{
  Node dummy;
  dummy.next = NULL;
  Node* tail = &dummy;

  while(1)
  {
    if(list1 == NULL)
    {
      tail -> next = list2;
      break;
    }
    else if(list2 == NULL)
    {
      tail -> next = list1;
      break;
    }

    if(list1 -> data <= list2 -> data)
    {
      tail -> next = list1;
      list1 = list1 -> next;
    }
    else
    {
      tail -> next = list2;
      list2 = list2 -> next;
    }

    tail = tail -> next;
  }

  return dummy.next;
}

Node* merge_two_lists_r(Node* l1_head, Node* l2_head) // Recursive approach
{
  if(l1_head == NULL) return l2_head;
  if(l2_head == NULL) return l1_head;

  if(l1_head -> data <= l2_head -> data)
  {
    l1_head -> next = merge_two_lists_r(l1_head -> next, l2_head);
    return l1_head;
  }
  else
  {
    l2_head -> next = merge_two_lists_r(l1_head, l2_head -> next);
    return l2_head;
  }
}

Node* get_node(int val)
{
  Node* new_node = malloc(sizeof(Node));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

void print(Node* head)
{
  if(head == NULL) return;
  printf("%d ", head -> data);
  print(head -> next);
}
