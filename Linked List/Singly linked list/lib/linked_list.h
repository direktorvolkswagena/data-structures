#pragma once

typedef struct node
{
  int data;
  struct node *next;
} Node;

// Creating node
Node *get_node(int val);
// Adding nodes
void list_push(Node **head, int val);
void list_append(Node **head, int val);
void list_insert(Node **head, int val, int pos);
//Deleting nodes
void list_del_beg(Node **head);
void list_del_end(Node *head);
void list_pop(Node **head, int pos);
void list_wipe(Node **head);
//Reversing list
void list_reverse(Node **head);
//Printing list
void list_display(Node *head);
void list_display_reversed(Node *head);
