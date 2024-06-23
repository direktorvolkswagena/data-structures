#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct qNode
{
  int data;
  struct qNode* next;
} qNode;

typedef struct
{
  qNode* head;
  qNode* tail;
  int size;
} Queue;

qNode* get_node(int val);
Queue* create_queue();
int q_size(Queue* queue);
bool q_is_empty(Queue* queue);
int q_peek(Queue* queue, bool* status);
void enqueue(Queue* queue, int val);
int dequeue(Queue* queue, bool* status);
void q_display(Queue* queue);
void q_destroy(Queue* queue);


int main()
{
  Queue* queue = create_queue();
  bool status = false;

  enqueue(queue, 15);
  enqueue(queue, 35);
  enqueue(queue, 75);

  q_display(queue);

  printf("\nFirst in queue: %d\n", q_peek(queue, &status));

  printf("\nQueue size: %d\n", q_size(queue));

  dequeue(queue, &status);

  q_display(queue);

  return 0;
}

qNode* get_node(int val)
{
  qNode* new_node = malloc(sizeof(qNode));

  new_node -> data = val;
  new_node -> next = NULL;

  return new_node;
}

Queue* create_queue()
{
  Queue* queue = malloc(sizeof(Queue));

  queue -> head = NULL;
  queue -> tail = NULL;
  queue -> size = 0;

  return queue;
}

int q_size(Queue* queue)
{
  return queue -> size;
}

bool q_is_empty(Queue* queue)
{
  return q_size(queue) == 0;
}

int q_peek(Queue* queue, bool* status)
{
  if(q_is_empty(queue))
  {
    *status = false;
    return -1;
  }

  *status = true;
  return queue -> head -> data;
}

void enqueue(Queue* queue, int val)
{
  qNode* new_node = get_node(val);

  if(q_is_empty(queue))
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

int dequeue(Queue* queue, bool* status)
{
  if(q_is_empty(queue))
  {
    *status = false;
    return -1;
  }

  *status = true;

  int res = queue -> head -> data;
  qNode* temp = queue -> head;

  if(q_size(queue) == 1)
  {
    queue -> head = NULL;
    queue -> tail = NULL;
  }

  queue -> head = queue -> head -> next;
  free(temp);
  queue -> size--;

  return res;
}

void q_display(Queue* queue)
{
  qNode* temp = queue -> head;

  if(q_is_empty(queue))
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

void q_destroy(Queue* queue)
{
  qNode* current_node = queue -> head;

  while(current_node != NULL)
  {
    qNode* temp = current_node;
    current_node = current_node -> next;
    free(temp);
  }

  free(queue);
}
