/*
Write a program in C to search for an existing element in a singly linked list.
Test Data and Expected Output :

Input the number of nodes : 3

Input data for node 1 : 2
Input data for node 2 : 5
Input data for node 3 : 8

Data entered in the list are :
Data = 2
Data = 5
Data = 8

Input the element to be searched : 5
Element found at node 2
*/

#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node* next;

  Node(int val): data(val), next(nullptr) {}
};

class LinkedList
{
private:
  Node* head;

public:
  LinkedList(): head(nullptr) {}

  void append(int val)
  {
    Node* new_node = new Node(val);

    if(head == nullptr)
    {
      head = new_node;
      return;
    }

    Node* last = head;

    while(last -> next != nullptr)
      last = last -> next;

    last -> next = new_node;
  }

  int find(int val)
  {
    int count = 1;
    Node* current = head;

    while(current -> data != val)
    {
      if(current -> next == NULL)
      {
        cout << "Element has not been found\n";
        return 0;
      }
      count++;
      current = current -> next;
    }
    return count;
  }

  void print()
  {
    if(head == nullptr)
    {
      cout << "List is empty!\n";
      return;
    }

    Node* current = head;

    while(current != nullptr)
    {
      cout << "Data = " << current -> data << endl;
      current = current -> next;
    }
  }

  ~LinkedList()
  {
    Node* current = head;

    while(current != nullptr)
    {
      Node* temp = current -> next;
      delete current;
      current = temp;
    }
  }
};

int main()
{
  LinkedList list;

  int n;
  cout << "Input the number of nodes : ";
  cin >> n;

  for(int i = 1; i <= n; i++)
  {
    int val;
    cout << "Input data for node " << i << " : ";
    cin >> val;
    list.append(val);
  }

  cout << "\nData entered in the list are : \n";
  list.print();

  int val1;
  cout << "\nInput the element to be searched : ";
  cin >> val1;
  int res = list.find(val1);

  if(res)
    cout << "\nElement found at position : " << res << endl;

  return 0;
}
