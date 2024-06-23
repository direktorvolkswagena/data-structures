#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char o); // Defining precedence of operators
char assosiativity(char o);
void infix_to_postfix(char eq[]);

int main()
{
  char eq[1000];
  printf("Enter equation:\n");
  fgets(eq, 1000, stdin);

  infix_to_postfix(eq);

  return 0;
}

int prec(char o)
{
  if(o == '^') return 3;
  if(o == '*' || o == '/') return 2;
  if(o == '+' || o == '-') return 1;
  return -1;
}

char associativity(char o)
{
  if(o == '^') return 'R';
  return 'L';
}

void infix_to_postfix(char eq[])
{
  char res[1000];
  int res_index = 0;
  int size = strlen(eq);
  char stack[1000];
  int top = -1;

  for(int i = 0; i < size; i++)
  {
    char t = eq[i];

    if(t == ' ') continue;

    if((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9'))
      res[res_index++] = t;

    else if(t == '(')
      stack[++top] = t;

    else if(t == ')')
    {
      while(top >= 0 && stack[top] != '(')
        res[res_index++] = stack[top--];

      top--;
    }
    else
    {
      while(top >= 0 && (prec(t) < prec(stack[top]) || prec(t) == prec(stack[top])
          && associativity(t) == 'L'))
            res[res_index++] = stack[top--];

      stack[++top] = t;
    }
  }

  while(top >= 0)
    res[res_index++] = stack[top--];

  res[res_index] = '\0';
  printf("%s\n", res);
}
