/*
Write a program in C to delete the first node of a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 2
Input data for node 2 : 3
Input data for node 3 : 4
Expected Output :

 Data entered in the list are :
 Data = 2
 Data = 3
 Data = 4

 Data of node 1 which is being deleted is :  2

 Data, after deletion of first node :
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

  void del_beg()
  {
    Node* temp = head;
    head = head -> next;
    cout << "\nData of node 1 which is being deleted is : " << temp->data << endl;
    delete temp;
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

  cout << "\nData entered in the list are : \n";
  list.print();

  list.del_beg();

  cout << "\nData, after deletion of first node : \n";
  list.print();

  return 0;
}
