/*
Write a C program that checks whether a string of parentheses is balanced or not using stack. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

#define MAX_SIZE 200

bool isValid(char *str);


int main()
{
    char str[MAX_SIZE];
    printf("Enter a string of parentheses:\n");
    fgets(str, MAX_SIZE, stdin);

    int len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';

    isValid(str) ? printf("Valid!\n") : printf("Invalid!\n");

    return 0;
}


bool isValid(char *str)
{
    int len = strlen(str);
    Stack stack;
    stack_init(&stack, len);

    for(int i = 0; i < len; i++)
    {
        char t = str[i];

        if(t == '(' || t == '{' || t == '[') stack_push(&stack, t);
        else
        {
            if(stack_isEmpty(&stack)) return false;

            char t2;
            if(t == ')' && stack_peek(&stack) == '(' ||
                t == '}' && stack_peek(&stack) == '{' ||
                t == ']' && stack_peek(&stack) == '[') t2 = stack_pop(&stack);
            else return false;
        }
    }
    return stack_isEmpty(&stack);
}
