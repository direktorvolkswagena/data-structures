/*
Write a C program to implement a stack that supports push, pop, get middle, and delete middle elements. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int stack_get_middle(Stack *stack);
void stack_get_middle_util(Stack *stack, int curr, int mid);
void stack_del_middle(Stack *stack);


int main()
{
    Stack stack;
    stack_init(&stack, 6);
    stack_push(&stack, 32);
    stack_push(&stack, 43);
    stack_push(&stack, 76);
    stack_push(&stack, 0);

    printf("Middle element of the stack is %d\n", stack_get_middle(&stack));

    printf("\nStack after removing middle element is: \n");
    stack_del_middle(&stack);
    stack_display(&stack);

    return 0;
}

int stack_get_middle(Stack *stack)
{
    int temp = (stack -> top) / 2;
    if ((stack -> top) % 2 == 0) return stack -> data[temp - 1];
    return stack -> data[temp];
}

void stack_get_middle_util(Stack *stack, int curr, int mid)
{
    int top = stack_pop(stack);

    if(curr != mid + 1)
    {
        stack_get_middle_util(stack, curr + 1, mid);
        stack_push(stack, top);
    }

    return;
}

void stack_del_middle(Stack *stack)
{
    if(stack_isEmpty(stack))
    {
        printf("Stack is empty!\n");
        return;
    }

    stack_get_middle_util(stack, 0, stack -> top / 2);
}