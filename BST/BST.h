  
//
//  BST.h
//  BST
//
//  Created by Lore Ang on 23/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include "NodeT.h"
#include <queue>
#include <stack>
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
    int height(NodeT *r);

  public:
    BST();
    ~BST();

    bool search(int data);
    void add(int data);
    void remove(int data);
    void print(int x);
    void printLeaves();
    int count();

    int height();
    void ancestors(int data);
    int whatLevelamI(int data);
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
    case 4:
      printLeaves(root);
      break;
    case 5:
        nivelXnivel();
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
    int left, right;

    left = count(r->getLeft());
    right = count(r->getRight());

    return 1 + left + right;
  }
  else
  {
    return 0;
  }
}

int BST::height(NodeT *r)
{
  int max, left, right;
            
  if (r == NULL)
  {
    return 0;
  }
  
  left = height(r->getLeft());
  right = height(r->getRight());
  
  max = (left > right ? left : right);
  
  return 1 + max;
}

int BST::height()
{
  return height(root);
}

void BST::ancestors(int data)
{
  NodeT* curr = root;
	stack<NodeT*> myStack;

	while (curr != NULL) 
  {
		if (curr->getData() == data) 
    {
			if (myStack.empty()) 
      {
				cout << "No ancestors.\n" << endl;
			}
			else 
      {
				while (!myStack.empty()) 
        {
					cout << myStack.top()->getData()<< " ";
					myStack.pop();
				}
				cout << endl;
			}
			return;
		}

		myStack.push(curr);
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}

  cout << "Data not in tree.\n";
}

int BST::whatLevelamI(int data)
{
  NodeT* curr = root;
	int level = 0;

	while (curr != NULL) 
  {
		if (curr->getData() == data) 
    {
			return level;
		}

		level++;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}

	return -1;
}

void BST::nivelXnivel()
{
  queue<NodeT*> myQueue;
  myQueue.push(root);
  
  while (!myQueue.empty())
  {
    NodeT *curr = myQueue.front();
    
    if (curr->getLeft() != NULL)
    {
      myQueue.push(curr->getLeft());
    }
    if (curr->getRight() != NULL)
    {
      myQueue.push(curr->getRight());
    }

    cout << curr->getData() << " ";
    myQueue.pop();
  }
}
