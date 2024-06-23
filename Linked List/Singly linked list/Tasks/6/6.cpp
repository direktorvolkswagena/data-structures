/*
Write a program in C to insert a node in the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes (3 or more) : 4
 Input data for node 1 : 1
 Input data for node 2 : 2
 Input data for node 3 : 3
 Input data for node 4 : 4

 Data entered in the list are :
 Data = 1
 Data = 2
 Data = 3
 Data = 4

 Input data to insert in the middle of the list : 5
 Input the position to insert new node : 3

 Insertion completed successfully.

 The new list are :
 Data = 1
 Data = 2
 Data = 5
 Data = 3
 Data = 4
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

  void insert(int val, int pos)
  {
    if(pos < 1)
    {
      cout << "Invalid Position!\n";
      return;
    }

    Node* new_node = new Node(val);

    if(pos == 1)
    {
      new_node -> next = head;
      head = new_node;
      return;
    }

    Node* current = head;

    pos--;
    while(pos != 1 && current != nullptr)
    {
      current = current -> next;
      pos--;

      if(current == nullptr)
      {
        cout << "Invalid position!\n";
        return;
      }
    }

    new_node -> next = current -> next;
    current -> next = new_node;

    cout << "\nInsertion completed successfully!\n";
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

  cout << "\nData entered in the list are :\n";
  list.print();

  int val1, pos;

  cout << "\nInput data to insert in the middle of the list : ";
  cin >> val1;

  cout << "\nInput the position to insert new node : ";
  cin >> pos;

  list.insert(val1, pos);

  cout << "\nThe new list are :\n";
  list.print();

  return 0;
}
