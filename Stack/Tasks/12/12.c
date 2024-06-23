/*
Write a C program to find the maximum element in a stack. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "stack.h"

int stack_max(Stack *stack, int max);

int main()
{
    Stack stack;
    stack_init(&stack, 7);
    stack_push(&stack, 12);
    stack_push(&stack, 16);
    stack_push(&stack, 534);
    stack_push(&stack, 872);
    stack_push(&stack, -32);
    stack_push(&stack, 9);
    stack_push(&stack, 32);
    stack_display(&stack);

    printf("Maximum element of the stack is %d\n", stack_max(&stack, INT_MIN));

    return 0;
}

int stack_max(Stack *stack, int max)
{
    if(!stack_isEmpty(stack))
    {
        int data = stack_pop(stack);
        if(data > max) max = data;

        max = stack_max(stack, max);
        stack_push(stack, data);
    }
    return max;
}