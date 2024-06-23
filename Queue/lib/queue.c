#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


qNode *get_node(int val)
{
  qNode* new_node = malloc(sizeof(qNode));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

Queue *create_queue()
{
  Queue *queue = malloc(sizeof(Queue));

  queue -> head = NULL;
  queue -> tail = NULL;
  queue -> size = 0;

  return queue;
}

int queue_size(Queue *queue)
{
  return queue -> size;
}

bool queue_isEmpty(Queue *queue)
{
  return queue_size(queue) == 0;
}

int queue_peek(Queue *queue, bool *status)
{
  if(queue_isEmpty(queue))
  {
    *status = false;
    return -1;
  }

  *status = true;
  return queue -> head -> data;
}

void enqueue(Queue *queue, int val)
{
  qNode *new_node = get_node(val);

  if(queue_isEmpty(queue))
  {
    queue -> head = new_node;
    queue -> tail = new_node;
    queue -> size++;
    return;
  }

  queue -> tail -> next = new_node;
  queue -> tail = new_node;

  queue -> size++;
}

int dequeue(Queue *queue, bool *status)
{
  if(queue_isEmpty(queue))
  {
    *status = false;
    return -1;
  }

  *status = true;

  int res = queue -> head -> data;
  qNode *temp = queue -> head;

  if(queue_size(queue) == 1)
  {
    queue -> head = NULL;
    queue -> tail = NULL;
  }

  queue -> head = queue -> head -> next;
  free(temp);
  queue -> size--;

  return res;
}

void queue_display(Queue *queue)
{
  qNode *temp = queue -> head;

  if(queue_isEmpty(queue))
  {
    printf("Queue is empty!\n");
    return;
  }

  printf("\nQueue: \n");

  while(temp)
  {
    printf("<- %d ", temp -> data);
    temp = temp -> next;
  }

  printf(" <- \n");
}

void queue_destroy(Queue *queue)
{
  qNode *current_node = queue -> head;

  while(current_node != NULL)
  {
    qNode *temp = current_node;
    current_node = current_node -> next;
    free(temp);
  }

  free(queue);
}
