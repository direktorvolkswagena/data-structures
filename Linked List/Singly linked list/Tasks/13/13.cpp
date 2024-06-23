/*
13. Write a C program to merge two sorted singly linked lists into a single sorted linked list.
Test Data and Expected Output :

Two sorted singly linked lists:
1 3 5 7
2 4 6

After merging the said two sorted lists:
1 2 3 4 5 6 7
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
      cout << "List is empty!\n";
      return;
    }

    Node* current = head;

    while(current != nullptr)
    {
      cout << current -> data << " ";
      current = current -> next;
    }
  }

// Case when we merge one list to another
  void merge(LinkedList& second_list)
  {
    if(second_list.head == nullptr)
      return;

    if(head == nullptr)
    {
      head = second_list.head;
      second_list.head = nullptr;
      return;
    }

    Node* list1 = head;
    Node* list2 = second_list.head;
    Node* prev = nullptr;

    while(list1 != nullptr && list2 != nullptr)
    {
      if(list1 -> data < list2 -> data)
      {
        prev = list1;
        list1 = list1 -> next;
      }
      else
      {
        Node* next = list2 -> next;
        list2 -> next = list1;
        if(prev != nullptr)
          prev -> next = list2;
        else
          head = list2;

        prev = list2;
        list2 = next;
      }
    }

    if(list2 != nullptr)
      prev -> next = list2;

    second_list.head = nullptr;
  }

// Case when we create a new list
  static LinkedList merge(LinkedList& list1, LinkedList& list2)
  {
    LinkedList merged;
    Node* ptr1 = list1.head;
    Node* ptr2 = list2.head;

    while (ptr1 != nullptr && ptr2 != nullptr)
    {
      if(ptr1 -> data < ptr2 -> data)
      {
        merged.append(ptr1 -> data);
        ptr1 = ptr1 -> next;
      }
      else
      {
        merged.append(ptr2 -> data);
        ptr2 = ptr2 -> next;
      }
    }

    // Add remaining elements of list1 if any
    while(ptr1 != nullptr)
    {
      merged.append(ptr1 -> data);
      ptr1 = ptr1 -> next;
    }

    // Add remaining elements of list2 if any
    while(ptr2 != nullptr)
    {
      merged.append(ptr2 -> data);
      ptr2 = ptr2 -> next;
    }

    return merged;
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
  LinkedList list1, list2;

  list1.append(12);
  list1.append(23);
  list1.append(143);
  list1.append(677);

  list2.append(1);
  list2.append(43);
  list2.append(123);
  list2.append(566);
  list2.append(2222);

  cout << "Two sorted singly linked lists: \n";
  list1.print();
  cout << endl;
  list2.print();

  // cout << "\nMerged singly linked lists: \n";
  // list1.merge(list2);
  // list1.print();
  // cout << endl;

  LinkedList merged = LinkedList::merge(list1, list2);
  cout << "\nMerged singly linked lists: \n";
  merged.print();

  return 0;
}
