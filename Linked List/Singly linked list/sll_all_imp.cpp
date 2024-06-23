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

  void push(int data)
  {
    Node* new_node = new Node(data);
    new_node -> next = head;
    head = new_node;
  }

  void insert(int val, int pos)
  {
    if(pos < 1)
    {
      cout << "Invalid position!\n";
      return;
    }

    Node* new_node = new Node(val);

    if (pos == 1)
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
    Node* current = head;

    if(head == nullptr)
    {
      cout << "List is empty!\n";
      return;
    }

    cout << "Linked list: ";

    while(current != nullptr)
    {
      cout << current -> data << " ";
      current = current -> next;
    }

    cout << "\n";
  }

  void del_beg()
  {
    Node* temp = head;
    head = head -> next;
    delete temp;
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

  void del_last()
  {
    if(head == nullptr)
    {
      cout << "List is empty!\n";
      return;
    }

    Node* current = head;
    Node* previous = head;

    while(current -> next != nullptr)
    {
      previous = current;
      current = current -> next;
    }

    delete current;
    previous -> next = nullptr;
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

  list.push(100);
  list.append(23);
  //list.push(20);

  list.print();

  return 0;
}
