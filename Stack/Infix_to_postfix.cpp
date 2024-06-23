#include <iostream>
#include <stack>

using namespace std;

void print_stack(stack<int> st);
int prec(char o);
char associativity(char o);
void infix_to_postfix(string eq);

int main()
{
  string exp;

  cout << "Enter equation: \n";
  getline(cin, exp);

  infix_to_postfix(exp);

  return 0;
}

void print_stack(stack<int> st)
{
  if(st.empty()) return;

  int t = st.top();

  st.pop();

  print_stack(st);

  cout << t << " ";

  st.push(t);
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
  return o == '^' ? 'R' : 'L';
}

void infix_to_postfix(string eq)
{
  stack<char> st;
  string res;

  for(int i = 0; i < eq.size(); i++)
  {
    char t = eq[i];

    if(t == ' ') continue;

    if((t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z') || (t >= '0' && t <= '9'))
      res += t;

    else if(t == '(')
      st.push(t);

    else if(t == ')')
    {
      while(st.top() != '(')
      {
        res += st.top();
        st.pop();
      }
      st.pop();
    }

    else
    {
      while(!st.empty() && prec(t) < prec(st.top()) ||
            !st.empty() && (prec(t) == prec(st.top()) && associativity(t) == 'L'))
            {
              res += st.top();
              st.pop();
            }
      st.push(t);
    }
  }

  while(!st.empty())
  {
    res += st.top();
    st.pop();
  }

  cout << res << endl;
}
