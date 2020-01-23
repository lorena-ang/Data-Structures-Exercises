//
//  BST.h
//  BST
//
//  Created by Lore Ang on 23/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include "NodeT.h"
#include <queue>
using namespace std;

class BST 
{
  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);

    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);

    void free(NodeT *r);
    void printLeaves(NodeT *r);
    int count(NodeT *r);
    void nivelXnivel();

  public:
    BST();
    ~BST();
    BST(const BST &copy);

    bool search(int data);
    void add(int data);
    void remove(int data);
    void print(int x);
    void printLeaves();
    int count();

    int height();
    void ancestors(int data);
    int whatlevelamI(int data); // Cambiar nombre
    
    int maxWidth();
    int nearstRelative(int n1, int n2); // Cambiar nombre
    bool operator==(const BST &ABB);
    queue<int> toQueue();
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  free(root);
}

bool BST::search(int data)
{
  NodeT *curr = root;

  while (curr != NULL)
  {
    if (curr->getData() == data)
    {
      return true;
    }

    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }

  return false;
}

void BST::add(int data)
{
  NodeT *father = NULL;
  NodeT *curr = root;

  while (curr != NULL)
  {
    father = curr;

    if (curr->getData() == data)
    {
      return;
    }

    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }

  if (father == NULL)
  {
    root = new NodeT(data);
  }
  else
  {
    if (father->getData() > data)
    {
      father->setLeft(new NodeT(data));
    }
    else
    {
      father->setRight(new NodeT(data));
    }
  }
}

int BST::howManyChildren(NodeT *r)
{
  int cont = 0;

  if (r->getLeft() != NULL)
  {
    cont++;
  }

  if (r->getRight() != NULL)
  {
    cont++;
  }

  return cont;
}

int BST::pred(NodeT *r)
{
  NodeT *curr = r->getLeft();

  while (curr != NULL && curr->getRight() != NULL)
  {
    curr = curr->getRight();
  }

  return curr->getData();
}

int BST::succ(NodeT *r)
{
  NodeT *curr = r->getRight();

  while (curr != NULL && curr->getLeft() != NULL)
  {
    curr = curr->getLeft();
  }

  return curr->getData();
}

void BST::remove(int data)
{
  NodeT *curr = root;
  NodeT *father = NULL;

  while (curr != NULL && curr->getData() != data)
  {
    father = curr;
    curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
  }

  if (curr == NULL)
  {
    return;
  }

  int c = howManyChildren(curr);

  switch (c)
  {
    case 0:
      if (father == NULL)
      {
        root = NULL;
      }
      else
      {
        if (father->getData() > data)
        {
          father->setLeft(NULL);
        }
        else
        {
          father->setRight(NULL);
        }
      }
      delete curr;
      break;
    case 1:
      if (father == NULL)
      {
        if (curr->getLeft() != NULL)
        {
          root = curr->getLeft();
        }
        else
        {
          root = curr->getRight();
        }
        
        // root = (curr->getLeft() != NULL) ? curr->getLeft() : curr->getRight
      }
      else
      {
        if (father->getData() > data)
        {
          if (curr->getLeft() != NULL)
          {
            father->setLeft(curr->getLeft());
          }
          else
          {
            if (curr->getLeft() != NULL)
            {
              father->setRight(curr->getLeft());
            }
            else
            {
              father->setRight(curr->getRight());
            }
          }
        }
      }
      delete curr;
      break;
    case 2:
      int x = succ(curr);
      remove(x);
      curr->setData(x);
      break;
  }
}

void BST::preOrder(NodeT *r)
{
  if (r != NULL)
  {
    cout << r->getData() << " ";
    preOrder(r->getLeft());
    preOrder(r->getRight());
  }
}

void BST::inOrder(NodeT *r)
{
  if (r != NULL)
  {
    inOrder(r->getLeft());
    cout << r->getData() << " ";
    inOrder(r->getRight());
  }
}

void BST::postOrder(NodeT *r)
{
  if (r != NULL)
  {
    postOrder(r->getLeft());
    postOrder(r->getRight());
    cout << r->getData() << " ";
  }
}

void BST::print(int x)
{
  switch (x)
  {
    case 1:
      preOrder(root);
      break;
    case 2:
      inOrder(root);
      break;
    case 3:
      postOrder(root);
      break;
  }

  cout << endl;
}

void BST::free(NodeT *r)
{
  if (r != NULL)
  {
    free(r->getLeft());
    free(r->getRight());
    delete r;
  }
}

void BST::printLeaves()
{
  printLeaves(root);
}

void BST::printLeaves(NodeT *r)
{
  if (r != NULL)
  {
    if (r->getLeft() == NULL && r->getRight() == NULL)
    {
      cout << r->getData() << " ";
    }
    else
    {
      printLeaves(r->getLeft());
      printLeaves(r->getRight());
    }
  }
}

int BST::count()
{
  return count(root);
}

int BST::count(NodeT *r)
{
  if (r != NULL)
  {
    return 1 + count(r->getLeft()) + count(r->getRight());
  }
  else
  {
    return 0;
  }
}

int BST::height()
{
  // NOT DONE YET
}

void BST::ancestors(int data)
{
  // NOT DONE YET
}

int BST::whatlevelamI(int data)
{
  // NOT DONE YET
}

int BST::maxWidth()
{
  // NOT DONE YET
}

int BST::nearstRelative(int n1, int n2)
{
  // NOT DONE YET
}

bool BST::operator==(const BST &ABB)
{
  // NOT DONE YET
}

queue<int> BST::toQueue()
{
  // NOT DONE YET
}
