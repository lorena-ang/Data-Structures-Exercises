//
//  LinkedList.h
//  LinkedList
//
//  Created by Lore Ang on 13/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include "Node.h"
using namespace std;

template <class T>
class LinkedList
{
  private:
    Node<T> *head;
    int size;
    void deleteHelper();
  
  public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &LL);

    bool isEmpty();
    int getSize();

    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);

    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();

    T get(int pos);
    T set(T data, int pos);
    bool change(int pos1, int pos2);

    void print();
    void reverse();
    void shift(int num);

    void operator=(const LinkedList<T> &LL);
    bool operator==(const LinkedList<T> &LL);
    void operator+=(T data);
    void operator+=(const LinkedList<T> &LL);
};

// Constructor
template <class T>
LinkedList<T>::LinkedList()
{
  head = NULL;
  size = 0;
}

// Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
  deleteHelper();
}

// Copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &LL)
{
  if (LL.size > 0)
  {
    Node<T> *curr2 = LL.head;
    head = new Node<T>(curr2->getData(), curr2->getNext());
    size = 1;

    Node<T> *curr1 = head;

    while (curr2->getNext() != NULL)
    {
      curr2 = curr2->getNext();
      curr1->setNext(new Node<T>(curr2->getData(), curr2->getNext()));
      curr1 = curr1->getNext();
      size++;
    }
    curr1->setNext(NULL);
  }
  else
  {
    size = 0;
    head = NULL;
  }  
}

// Check if linked list is empty
template <class T>
bool LinkedList<T>::isEmpty()
{
  // return (size == 0);
  return (head == NULL);
}

// Get the size
template <class T>
int LinkedList<T>::getSize()
{
  return size;
}

// Create node at start of list with given data
template <class T>
void LinkedList<T>::addFirst(T data)
{
  head = new Node<T>(data, head);
  size++;
}

// Add node at the end of list with given data
template <class T>
void LinkedList<T>::addLast(T data)
{
  if (this->isEmpty())
  {
    addFirst(data);
  }
  else
  {
    Node<T> *curr = head;
    while (curr->getNext() != NULL)
    {
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data)); 
    size++;
  }
}

// Add a node with given data in given position
template <class T>
bool LinkedList<T>::add(T data, int pos)
{
  if (pos > size)
  {
    return false;
  }

  if (pos == size)
  {
    addLast(data);
  }
  else if (pos == 0)
  {
    addFirst(data);
  }
  else
  {
    Node<T> *curr = head;
    for (int i = 0; i < pos - 1; i++)
    {
      curr = curr->getNext();
    }

    curr->setNext(new Node<T>(data, curr->getNext()));
    size++;
  }

  return true;  
}

// Delete all nodes
template <class T>
void LinkedList<T>::deleteHelper()
{
  Node<T> *curr = head;

  while (!this->isEmpty())
  {
    // deleteFirst();
    head = head->getNext();
    delete curr;
    curr = head;
  }
}

// Delete first node
template <class T>
void LinkedList<T>::deleteFirst()
{
  if (!this->isEmpty())
  {
    Node<T> *curr = head;
    head = head->getNext();
    delete curr;
    size--;
  }
}

// Delete last node
template <class T>
void LinkedList<T>::deleteLast()
{
  if (size < 2)
  {
    deleteFirst();
  }
  else
  {
    Node<T> *curr = head;
    while (curr->getNext()->getNext() != NULL)
    {
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    size--;
  }
}

// Delete node in given position
template <class T>
void LinkedList<T>::del(int pos)
{
  if (pos == 0)
  {
    deleteFirst();
  }
  else if (pos == size - 1)
  {
    deleteLast();
  }
  else
  {
    Node<T> *curr = head;
    for (int i = 0; i < pos - 1; i++)
    {
      curr = curr->getNext();
    }

    Node<T> *temp = curr->getNext();
    curr->setNext(temp->getNext());
    delete temp;
    size--;
  }
}

// Delete all nodes and return previous size
template <class T>
int LinkedList<T>::deleteAll()
{
  int cant = size;
  deleteHelper();
  size = 0;

  return cant;
}

// Get data from the position given
template <class T>
T LinkedList<T>::get(int pos)
{
  Node<T> *curr = head;

  for (int i = 0; i < pos; i++)
  {
    curr = curr->getNext();
  }

  return curr->getData();
}

// Change data in given position
template <class T>
T LinkedList<T>::set(T data, int pos)
{
  Node<T> *curr = head;

  for (int i = 0; i < pos; i++)
  {
    curr = curr->getNext();
  }

  T prev = curr->getData();
  curr->setData(data);
  return prev;
}

// Interchange two nodes in given positions
template <class T>
bool LinkedList<T>::change(int pos1, int pos2)
{
  if (pos1 == pos2)
  {
    return true;
  }

  int max = (pos1 > pos2 ? pos1 : pos2);
  int min = (pos1 < pos2 ? pos1 : pos2);
  
  Node<T> *curr1 = head;
  for (int i = 0; i < min; i++)
  {
    curr1 = curr1->getNext();
  }

  Node<T> *curr2 = curr1;
  for (int i = min; i < max; i++)
  {
    curr2 = curr2->getNext();
  }

  T prev = curr1->getData();
  curr1->setData(curr2->getData());
  curr2->setData(prev);
  
  return true;
}

// Print data from all nodes
template <class T>
void LinkedList<T>::print()
{
  Node<T> *curr = head;
  while (curr != NULL)
  {
    cout << curr->getData() << " ";
    curr = curr->getNext();
  }
  cout << endl;
}

// Reverse list
template <class T>
void LinkedList<T>::reverse()
{
  Node<T> *curr = head;
  Node<T> *prev = NULL;
  Node<T> *next;

  while (curr != NULL)
  {
    next = curr->getNext();
    curr->setNext(prev);
    prev = curr;
    curr = next;
  }
  
  head = prev;
}

// Shift given number of positions
template <class T>
void LinkedList<T>::shift(int num)
{
  if (num > 0)
  {
    for (int i = 0; i < num; i++)
    {
      Node<T> *next = head;
      Node<T> *prev = head;

      while (head->getNext() != NULL)
      {
        if (head->getNext()->getNext() == NULL)
        {
          prev = head;
        }

        head = head->getNext();
      }

      head->setNext(next);
      prev->setNext(NULL);
    }
  }

  if (num < 0)
  {
    num = -num;
    
    for (int i = 0; i < num; i++)
    {
      Node<T> *next = head;
      Node<T> *prev = head;

      head = head->getNext();

      while (next->getNext() != NULL)
      {
        next = next->getNext();
      }

      prev->setNext(NULL);
      next->setNext(prev);
    }
  }
}

// Assigns a complete linked list
template <class T>
void LinkedList<T>::operator=(const LinkedList<T> &LL)
{
  deleteAll();
  
  if (LL.size > 0)
  {
    Node<T> *currNew = LL.head;
    head = new Node<T>(currNew->getData(), currNew->getNext());
    size++;

    Node<T> *currPrev = head;
    currNew = currNew->getNext();

    while (currNew->getNext() != NULL)
    {
      Node<T> *aux = new Node<T>(currNew->getData(), currNew->getNext());
      currPrev->setNext(aux);
      size++;
      currPrev = currPrev->getNext();
      currNew = currNew->getNext();
    }
  }
}

// Checks if two linked lists have the same content and order
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &LL)
{
  if (size == 0 && LL.size == 0)
  {
    return true;
  }
  
  if (size != LL.size)
  {
    return false;
  }
  else
  {
    Node<T> *curr1 = head;
    Node<T> *curr2 = LL.head;

    if (curr1->getData() != curr2->getData())
    {
      return false;
    }

    while (curr1->getNext() != NULL)
    {
      curr1 = curr1->getNext();
      curr2 = curr2->getNext();

      if (curr1->getData() != curr2->getData())
      {
        return false;
      }
    }

    return true;
  }
}

// Adds a new node at the end with given data
template <class T>
void LinkedList<T>::operator+=(T data)
{
  addLast(data);
}

// Adds all given linked list's information to the end of linked list
template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &LL)
{
  Node<T> *curr1 = head;
  Node<T> *curr2 = LL.head;
  int last = size;

  while (curr1->getNext() != NULL)
  {
    curr1 = curr1->getNext();
  }

  add(curr2->getData(), last);
  last++;

  while (curr2->getNext() != NULL)
  {
    curr2 = curr2->getNext();
    add(curr2->getData(), last);
    last++;
  }  
}
