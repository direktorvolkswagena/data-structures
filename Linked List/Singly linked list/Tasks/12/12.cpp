/*
Write a C program that converts a singly linked list into an array and returns it.
Test Data and Expected Output :


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
#include <vector>

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

//classic approach
  int* list_to_arr(int size)
  {
    int* arr = new int[size];

    Node* current = head;

    int i = 0;

    while(current != nullptr)
    {
      arr[i++] = current -> data;
      current = current -> next;
    }

    return arr;
  }

//vector approach
  vector<int> list_to_arr_v()
  {
    vector<int> arr;

    Node* current = head;

    while(current != nullptr)
    {
      arr.push_back(current -> data);
      current = current -> next;
    }
    return arr;
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

  int* arr = list.list_to_arr(n);
  cout << "\nArray representation of singly linked list is: \n";

  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";

  delete[] arr;

  vector<int> a = list.list_to_arr_v();
  cout << "\nArray representation of singly linked list using vector is: \n";

  for(int i = 0; i < a.size(); i++)
    cout << a[i] << " ";

  return 0;
}
