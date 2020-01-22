//
//  Queue.h
//  Queue
//
//  Created by Lore Ang on 19/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include "Node.h"

template<class T>
class Queue
{
  private:
    Node<T> *fin;
    int size;

  public:
    Queue();
    ~Queue();

    void push(T data);
    void pop();
    T front();
    bool empty();
    int getSize();
};

template<class T>
Queue<T>::Queue()
{
  fin = NULL;
  size = 0;
}

template<class T>
Queue<T>::~Queue()
{
  if (fin != NULL)
  {
    Node<T> *curr = fin->getNext();
    fin->setNext(NULL);
    fin = curr;

    while (fin != NULL)
    {
      fin = fin->getNext();
      delete curr;
      curr = fin;
    }
  }
}

template<class T>
void Queue<T>::push(T data)
{
  if (fin == NULL)
  {
    fin = new Node<T>(data);
    fin->setNext(fin);
  }
  else
  {
    fin->setNext(new Node<T>(data, fin->getNext()));
    fin = fin->getNext();
  }
  size++;
}

template<class T>
void Queue<T>::pop()
{
  Node<T> *curr = fin->getNext();

  if (curr == fin)
  {
    fin = NULL;
  }
  else
  {
    fin->setNext(curr->getNext());
  }

  delete curr;
  size--;
}

template<class T>
T Queue<T>::front()
{
  return fin->getNext()->getData();
}

template<class T>
bool Queue<T>::empty()
{
  return fin == NULL;
}

template<class T>
int Queue<T>::getSize()
{
  return size;
}
