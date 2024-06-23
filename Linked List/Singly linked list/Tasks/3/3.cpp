/*
Write a program in C to create a singly linked list of n nodes and count the
number of nodes.

Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7

Expected Output :
Data entered in the list are :
Data = 5
Data = 6
Data = 7
Total number of nodes = 3
*/

#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

class LinkedList
{
private:
  Node* head;

public:
  LinkedList() {head = nullptr;}

  Node* get_node(int val)
  {
    Node* new_node = new Node();

    new_node -> data = val;
    new_node -> next = nullptr;

    return new_node;
  }

  void print()
  {
    Node* current = head;

    if (current == nullptr)
    {
      cout << "List is empty!\n";
      return;
    }
    else
    {
      while(current != nullptr)
      {
        cout << "Data = " << current -> data << '\n';
        current = current -> next;
      }
    }
  }

  void append(int val)
  {
    Node* new_node = get_node(val);

    if(head == nullptr)
    {
      head = new_node;
      return;
    }
    else
    {
      Node* last = head;

      while(last -> next != nullptr)
        last = last -> next;

      last -> next = new_node;
    }
  }

  int count_nodes()
  {
    Node* temp = head;

    int counter = 0;

    while(temp != nullptr)
    {
      counter++;
      temp = temp -> next;
    }

    return counter;
  }

  ~LinkedList()
  {
    Node* current = head;

    while(current != nullptr)
    {
      Node* temp = current -> next;
      delete(current);
      current = temp;
    }
  }
};


int main()
{
  LinkedList list;

  int n;
  cout << "\nInput the number of nodes : ";
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

  cout << "\nTotal number of nodes = " << list.count_nodes();
  return 0;
}
