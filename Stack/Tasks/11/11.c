/*
Write a C program to find the minimum element in a stack. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "stack.h"

int stack_min(Stack *stack, int min);

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

    printf("Minimum element in the stack is %d\n", stack_min(&stack, INT_MAX));

    return 0;
}


int stack_min(Stack *stack, int min)
{
    if(!stack_isEmpty(stack))
    {
        int temp = stack_pop(stack);
        if(temp < min) min = temp;

        min = stack_min(stack, min);
        stack_push(stack, temp);   
    }
    return min;
}
