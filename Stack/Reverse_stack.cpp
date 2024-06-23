#include <iostream>
#include <stack>

using namespace std;

void reverse_stack(stack<int> &st);
void print_stack(stack<int> st);

int main()
{
  stack<int> st;

  st.push(12);
  st.push(225);
  st.push(32);
  st.push(41);

  print_stack(st);
  cout << endl;
  
  reverse_stack(st);

  print_stack(st);

  return 0;
}

void reverse_stack(stack<int> &st)
{
    stack<int> temp1, temp2;

    while(!st.empty())
    {
        temp1.push(st.top());
        st.pop();
    }

    while(!temp1.empty())
    {
        temp2.push(temp1.top());
        temp1.pop();
    }

    while(!temp2.empty())
    {
        st.push(temp2.top());
        temp2.pop();
    }
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
