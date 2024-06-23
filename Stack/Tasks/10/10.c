/*
Write a C program that reverses a stack using only stack operations push and pop. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


void push_to_bottom(Stack* stack, int val);
void stack_reverse(Stack *stack);


int main()
{
    Stack stack;
    stack_init(&stack, 7);
    stack_push(&stack, 143);
    stack_push(&stack, 542);
    stack_push(&stack, 132);
    stack_push(&stack, 11);
    stack_push(&stack, 32);
    stack_push(&stack, 0);
    stack_display(&stack);

    stack_reverse(&stack);
    stack_display(&stack);

    stack_destroy(&stack);

    return 0;
}

void push_to_bottom(Stack* stack, int val)
{
    if(stack_isEmpty(stack)) stack_push(stack, val);
    else
    {
        int temp = stack_pop(stack);
        push_to_bottom(stack, val);
        stack_push(stack, temp);
    } 
}

void stack_reverse(Stack *stack)
{
    if(!stack_isEmpty(stack))
    {
        int temp = stack_pop(stack);
        stack_reverse(stack);
        push_to_bottom(stack, temp);
    }
    else return;
}