/*
Write a C program that accepts a string and reverse it using a stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

#define STR_LIMIT 500

char *reverse(char *str);


int main()
{
  char str[STR_LIMIT];
  printf("Enter a string:\n");
  fgets(str, STR_LIMIT, stdin);

  reverse(str);

  return 0;
}


char *reverse(char *str)
{
  int len = strlen(str);
  if (len > 0 && str[len - 1] == '\n')
  {
    str[len - 1] = '\0';
    len--;
  }

  Stack stack;
  stack_init(&stack, len);

  for (int i = 0; i < len; i++)
    stack_push(&stack, str[i]);

  char *res = malloc((len + 1) * sizeof(char)); 

  for (int i = 0; i < len; i++)
    res[i] = stack_pop(&stack);

  res[len] = '\0';  // Null-terminate the result string

  printf("\nResult: \n%s", res);

  stack_destroy(&stack);  // Clean up the allocated memory

  return res;
}