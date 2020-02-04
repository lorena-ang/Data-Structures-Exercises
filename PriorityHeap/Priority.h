//
//  Priority.h
//  PriorityHeap
//
//  Created by Lore Ang on 1/2/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <vector>
using namespace std;

class Priority
{
  private:
    vector<int> heap;
    bool priority;
    int getParent(int child);
    void swap(int parent, int child);
    void checkUp(bool priority);
    void checkDown(bool priority);

  public:
    Priority();
    Priority(bool priority);
    void push(int data);
    void pop();
    void top();
    int size();
    bool empty();
    void print();
};

Priority::Priority()
{
  priority = true;
}

Priority::Priority(bool priority)
{
  this->priority = priority;
}

int Priority::getParent(int child)
{
  int parent;

  if (child % 2 == 0)
  {
    parent = (child / 2) - 1;
  }
	else
  {
    parent = child / 2;
  }

  return parent;
}

void Priority::swap(int parent, int child)
{
  int temp;

  temp = heap[child];
  heap[child] = heap[parent];
  heap[parent] = temp;
}

void Priority::checkUp(bool priority)
{
  int child, parent;

  child = heap.size() - 1;
  parent = getParent(child);
  
  if (priority)
  {
    while (heap[child] > heap[parent] && child >= 0 && parent >= 0)
    {
      swap(parent, child);
      child = parent;
      parent = getParent(child);
    }
  }
  else
  {
    while (heap[child] < heap[parent] && child >= 0 && parent >= 0)
    {
      swap(parent, child);
      child = parent;
      parent = getParent(child);
    }
  }
}

void Priority::checkDown(bool priority)
{
  int max, min, left, right, size;
  
  int parent = 0;
  
  if (priority)
  {
    while (true)
    {
      left = 2 * parent + 1;
      right = 2 * parent + 2;
      size = heap.size();
      max = parent;

      if (left < size && heap[left] > heap[max])
      {
        max = left;
      }

      if (right < size && heap[right] > heap[max])
      {
        max = right;
      }

      if (max != parent)
      {
        swap(parent, max);
        parent = max;
      }
      else
      {
        return;
      }
    }
  }
  else
  {
    while (true)
    {
      left = 2 * parent + 1;
      right = 2 * parent + 2;
      size = heap.size();
      min = parent;

      if (left < size && heap[left] < heap[min])
      {
        min = left;
      }

      if (right < size && heap[right] < heap[min])
      {
        min = right;
      }

      if (min != parent)
      {
        swap(parent, min);
        parent = min;
      }
      else
      {
        return;
      }
    }
  } 
}

void Priority::push(int data)
{
  heap.push_back(data);

  checkUp(priority);
}

void Priority::pop()
{
  int child = size() - 1;
  swap(0, child);

  heap.pop_back();

  checkDown(priority);
}

void Priority::top()
{
  cout << heap[0] << endl;
}

int Priority::size()
{
  return heap.size();
}

bool Priority::empty()
{
  return (size() == 0);
}

void Priority::print()
{
  for (int i = 0; i < heap.size(); ++i)
  {
    cout << heap[i] << " ";	    
  }
	
  cout << endl;
}
