#pragma once

typedef struct qNode
{
  int data;
  struct qNode *next;
} qNode;

typedef struct
{
  qNode* head;
  qNode* tail;
  int size;
} Queue;

qNode *get_node(int val);
Queue *create_queue();
int queue_size(Queue *queue);
bool queue_isEmpty(Queue *queue);
int queue_peek(Queue *queue, bool *status);
void enqueue(Queue *queue, int val);
int dequeue(Queue *queue, bool *status);
void queue_display(Queue *queue);
void queue_destroy(Queue *queue);
