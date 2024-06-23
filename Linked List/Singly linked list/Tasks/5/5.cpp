/*
Write a program in C to insert a new node at the end of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7

Data entered in the list are :
Data = 5
Data = 6
Data = 7

Input data to insert at the end of the list : 8

Data, after inserted in the list are :
Data = 5
Data = 6
Data = 7
Data = 8
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

  void print()
  {
    if(head == nullptr)
    {
      cout << "List is empty!\n" << endl;
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
      delete(current);
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

  cout << "\nData entered in the list are :\n";
  list.print();

  int val1;
  cout << "\nInput data to insert at the end of the list : ";
  cin >> val1;

  list.append(val1);

  cout << "\nData, after inserted in the list are : \n";
  list.print();



  return 0;
}
