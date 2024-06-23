#pragma once

#include <stdbool.h>

typedef struct
{
  int *data;
  int top;
  int size;
} Stack;


void stack_init(Stack *stack, int size);
void stack_destroy(Stack *stack);
bool stack_isFull(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, char val);
char stack_pop(Stack *stack);
char stack_peek(Stack *stack);
void stack_display(Stack *stack);
