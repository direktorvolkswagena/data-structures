/*
Write a program in C to delete a node from the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
 Input data for node 1 : 2
 Input data for node 2 : 5
 Input data for node 3 : 8

 Data entered in the list are :
 Data = 2
 Data = 5
 Data = 8

 Input the position of node to delete : 2

 Deletion completed successfully.

 The new list are  :
 Data = 2
 Data = 8
*/

#include <iostream>

using namespace std;

class Node
{
public:
  int data;
  Node* next;

  Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
  Node* head;

public:
  LinkedList() : head(nullptr) {}

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

  void pop(int pos)
  {
    if(pos < 1)
    {
      cout << "Invalid position!\n";
      return;
    }

    Node* current = head;
    Node* previous = head;

    if(pos == 1)
    {
      head = head -> next;
      delete current;
    }
    else
    {
      while(pos != 1)
      {
        previous = current;
        current = current -> next;
        pos--;

        if(current == nullptr)
        {
          cout << "Invalid position!\n";
          return;
        }
      }
      previous -> next = current -> next;
      delete current;
    }
    cout << "\nDeletion completed successfully!\n";
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

  int pos;
  cout << "\nInput the position of node to delete : ";
  cin >> pos;

  list.pop(pos);

  cout << "\nThe new list are : \n";
  list.print();

  return 0;
}
