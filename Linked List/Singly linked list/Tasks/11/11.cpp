/*
Linked List: Convert a Singly Linked list into a string
-------------------------------------------------------------
Input the number of nodes: 3
 Input data for node 1 : 10
 Input data for node 2 : 20
 Input data for node 3 : 30

Return data entered in the list as a string:
The linked list: 10 20 30
*/

#include <iostream>
#include <sstream>

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

// 1st approach:
  string list_to_str()
  {
    string res;
    Node* current = head;

    while(current != nullptr)
    {
      res += to_string(current -> data) + " "; // ass opposition to C sprintf(res, "%d ", current-> data)
      current = current -> next;
    }

    return res;
  }

  string list_to_str_2()
  {
    stringstream temp;
    Node* current = head;

    while(current != nullptr)
    {
      temp << current -> data << " ";
      current = current -> next;
    }

    return temp.str();
  }

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

  string lst = list.list_to_str();
  cout << "\nString representation of singly linked list is: \n" << lst;

  return 0;
}
