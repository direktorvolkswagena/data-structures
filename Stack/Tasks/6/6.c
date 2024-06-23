/*
Write a C program to sort a given stack using another stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void stack_reverse(Stack *stack);

int main()
{
    // Defining an input stack
    Stack input_stack;
    stack_init(&input_stack, 6);
    stack_push(&input_stack, 1);
    stack_push(&input_stack, 5);
    stack_push(&input_stack, 5);
    stack_push(&input_stack, 2);
    stack_push(&input_stack, 3);
    stack_push(&input_stack, 8);
    printf("Original");
    stack_display(&input_stack);

    stack_reverse(&input_stack);

    printf("Sorted");
    stack_display(&input_stack);

    return 0;
}

void stack_reverse(Stack *stack)
{
    Stack temp_stack;
    stack_init(&temp_stack, stack -> size);

    while(!stack_isEmpty(stack))
    {
        int temp = stack_pop(stack);

        while(!stack_isEmpty(&temp_stack) && stack_peek(&temp_stack) > temp)
        {
            stack_push(stack, stack_pop(&temp_stack));
        }

        stack_push(&temp_stack, temp);
    }

    while(!stack_isEmpty(&temp_stack))
    {
        stack_push(stack, stack_pop(&temp_stack));
    }
}