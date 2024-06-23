#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s);

int main()
{
  string s;
  cout << "Enter equation:\n";
  cin >> s;

  isValid(s) ? cout << "Valid!\n" : cout << "Invalid!\n";

  return 0;
}

bool isValid(string s)
{
  stack<char> st;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
    else
    {
      if(st.empty()) return false;

      if((s[i] == ')' && st.top() == '(') ||
         (s[i] == '}' && st.top() == '{') ||
         (s[i] == ']' && st.top() == '[')) st.pop();
      else return false;
    }
  }
  return st.empty();
}
