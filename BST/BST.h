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
#include <vector>
using namespace std;

class BST 
{
  private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);
    
    void preOrder(NodeT *r);
    void preOrderQueue(NodeT *r, queue<int> &myQueue);
    void inOrder(NodeT *r);
    void convInOrderQueue(NodeT *r, queue<int> &myQueue);
    void postOrder(NodeT *r);

    void free(NodeT *r);
    void printLeaves(NodeT *r);
    int count(NodeT *r);
    void nivelXnivel();
    int height(NodeT *r);
    vector<int> ancestorsVector(int data);

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
    int whatLevelamI(int data);

    queue<int> toQueue();
    bool operator==(const BST &ABB);
    int nearestRelative(int n1, int n2);
    int nearestRelative2(int n1, int n2);
    int maxWidth();
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  free(root);
}

BST::BST(const BST &copy)
{
  queue<NodeT*> nodes;

  NodeT *newRoot = copy.root;
  nodes.push(newRoot);

  root = NULL;

  while (!nodes.empty())
  {
    NodeT *curr = nodes.front();

    if (curr != NULL)
    {
      add(curr->getData());
      nodes.push(curr->getLeft());
      nodes.push(curr->getRight());
    }
    
    nodes.pop();
  }
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

void BST::preOrderQueue(NodeT *r, queue<int> &myQueue)
{
  if (r != NULL)
  {
    myQueue.push(r->getData());
    preOrderQueue(r->getLeft(), myQueue);
    preOrderQueue(r->getRight(), myQueue);
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

void BST::convInOrderQueue(NodeT *r, queue<int> &myQueue)
{
  if (r != NULL)
  {
    convInOrderQueue(r->getRight(), myQueue);
    myQueue.push(r->getData());
    convInOrderQueue(r->getLeft(), myQueue);
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

vector<int> BST::ancestorsVector(int data)
{
  NodeT *curr = root;
  vector<int> ancestors;
  stack<int> myStack;

  while (curr != NULL && curr->getData() != data)
  {
    myStack.push(curr->getData());
    curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
  }

  if (curr != NULL)
  {
    while (!myStack.empty())
    {
      ancestors.emplace_back(myStack.top());
      myStack.pop();
    }
  }

  return ancestors;
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

queue<int> BST::toQueue()
{
  queue<int> myQueue;

  convInOrderQueue(root, myQueue);

  return myQueue;
}

bool BST::operator==(const BST &ABB)
{
  BST temp = ABB;
  queue<int> q1, q2;
  int size;

  preOrderQueue(root, q1);
  preOrderQueue(temp.root, q2);

  if (q1.size() != q2.size())
  {
    return false;
  }
  else
  {
    size = q1.size();
    for (int i = 0; i < size; i++)
    {
      if (q1.front() != q2.front())
      {
        return false;
      }

      q1.pop();
      q2.pop();
    }

    return true;
  }
}

// Not counting itself as an ancestor
int BST::nearestRelative(int n1, int n2)
{
  vector<int> v1, v2;
  int size1, size2;

  if (!search(n1) && !search(n2))
  {
    return -1;
  }

  if (count(root) <= 1)
  {
    return -1;
  }

  v1 = ancestorsVector(n1);
  v2 = ancestorsVector(n2);

  size1 = v1.size();
  size2 = v2.size();

  for (int i = 0; i < size1; i++)
  {
    for (int j = 0; j < size2; j++)
    {
      if (v1[i] == v2[j])
      {
        return v1[i];
      }
    }
  }

  return -1;
}

// Counting itself as an ancestor
int BST::nearestRelative2(int n1, int n2)
{
  NodeT *curr = root;

  while (curr != NULL) 
  {
    int data = curr->getData();

    if (n1 > data && n2 > data) 
    {
      curr = curr->getRight();
    } 
    else if (n1 < data && n2 < data)
    {
      curr = curr->getLeft();
    } 
    else 
    {
      return curr->getData();
    }
  }

  return -1;
}

int BST::maxWidth()
{
  queue<NodeT*> nodes;
  int width = 0;

  if (root == NULL)
  {
    return 0;
  }

  nodes.push(root);

  while (!nodes.empty())
  {
    int size = nodes.size();

    width = max(size, width);

    while (size--)
    {
      NodeT *curr = nodes.front();
      nodes.pop();

      if (curr->getLeft() != NULL)
      {
        nodes.push(curr->getLeft());
      }

      if (curr->getRight() != NULL)
      {
        nodes.push(curr->getRight());
      }
    }
  }

  return width;
}