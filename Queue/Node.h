  
//
//  Node.h
//  Node
//
//  Created by Lore Ang on 19/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

template <class T>

class Node 
{
  private:
    T data;
    Node<T> *next;

  public:
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext();
    void setData(T data);
    void setNext(Node<T> *next);
};

template <class T>
Node<T>::Node(T data)
{
  this->data = data;
  next = NULL;
}

template <class T>
Node<T>::Node(T data, Node<T> *next)
{
  this->data = data;
  this->next = next;
}

template <class T>
T Node<T>::getData()
{
  return data;
}

template <class T>
Node<T>* Node<T>::getNext()
{
  return next;
}

template <class T>
void Node<T>::setData(T data)
{
  this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next)
{
  this->next = next;
}