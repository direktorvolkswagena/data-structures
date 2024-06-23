/*
Write a program in C to create a singly linked list of n nodes and display it in
reverse order.

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

 The list in reverse are :
 Data = 7
 Data = 6
 Data = 5
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
  LinkedList() : head(nullptr) {}

  Node* get_node(int val)
  {
    Node* new_node = new Node();

    new_node -> data = val;
    new_node -> next = nullptr;

    return new_node;
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

  void print()
  {
    Node* current = head;

    if(current == nullptr)
    {
      cout << "List is empty!\n";
      return;
    }
    else
    {
      while(current != nullptr)
      {
        cout << "Data = " << current -> data << endl;
        current = current -> next;
      }
    }
  }

  void rev_print_log(Node* current)
  {
    if(current == nullptr)
      return;
    rev_print_log(current -> next);
    cout << "Data = " << current -> data << endl;
  }

  void rev_print()
  {
    rev_print_log(head);
    cout << endl;
  }

  ~LinkedList()
  {
    Node* current = head;

    while(current != nullptr)
    {
      Node* temp = current;
      free(current);
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

  for (int i = 1; i <= n; i ++)
  {
    int val;
    cout << "Input data for node " << i << " : ";
    cin >> val;
    list.append(val);
  }

  cout << "\nData entered in the list are : \n";
  list.print();

  cout << "\nThe list in reverse are : \n";
  list.rev_print();

  return 0;
}
