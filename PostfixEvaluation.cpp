//
//  main.cpp
//  Postfix Expression Evaluation
//
//  Created by Lore Ang on 21/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

/*
Process the sequence of elements written in postfix notation from left to right (ex. 7 4 – 5 *):
- For each number, push it into the stack.
- For each operator, pop two elements from the stack, say X and Y (where X is the first element popped 
from the stack), perform the operation Y op X; push the result onto the stack.

After processing all elements, the stack should contain one single element: the value of the postfix
expression. For instance, the postfix expression 7 4 - 5 * is evaluated by performing the following 
actions:
- Reads number 7, push 7 into the stack.
- Reads number 4, push 4 into the stack.
- Reads operator -, pop two elements from stack: X = 4, Y = 7, perform
  operation Y - X = 7 – 4 = 3, push answer 3 into stack.
- Reads number 5, push 5 into the stack.
- Reads operator *, pop two elements from stack: X = 5, Y = 3, perform operation Y * X = 3 * 5 = 15, 
  push answer 15 into stack.
- The value of the expression, 15, sits alone in the stack.

What would be the result if the stack was replaced by other data structures, such as a queue or a minimum 
priority queue?

Input:
There are several cases; each test case consists of one line containing the postfix expression to be 
evaluated. This expression is guaranteed to be a valid expression written in postfix consisting of a
sequence of non-negative integers and operators +, -, *, all separated by a single space. The length of each
line does not exceed 100 characters. All input, intermediate, and final values will fit in a 32-bit signed
integer. The input ending with a line with #.
7 4 - 5 *
3 2 4 * +
3 4 2 - *
42 7 - 3 * 2 4 + *
5 3 5 - * 11 2 - 1 * -
#

Output:
For each test case, output a line with three spaced-separated integers: the values of the expression when
evaluated with a stack, queue, and minimum priority queue, respectively.
15 -15 15
11 10 10
6 2 4
630 -412 630
-19 41 3
*/

// Perform the "+", "-", or "*" operations in a stack
void stackOperation(string sD, stack<int> &myStack)
{
  int iX, iY;

  iX = myStack.top();
  myStack.pop();
  iY = myStack.top();
  myStack.pop();
  
  if (sD == "+")
  {
    myStack.push(iY + iX);
  }
  else if (sD == "-")
  {
    myStack.push(iY - iX);
  }
  else if (sD == "*")
  {
    myStack.push(iY * iX);
  }
}

// Perform the "+", "-", or "*" operations in a queue
void queueOperation(string sD, queue<int> &myQueue)
{
  int iX, iY;

  iX = myQueue.front();
  myQueue.pop();
  iY = myQueue.front();
  myQueue.pop();
  
  if (sD == "+")
  {
    myQueue.push(iY + iX);
  }
  else if (sD == "-")
  {
    myQueue.push(iY - iX);
  }
  else if (sD == "*")
  {
    myQueue.push(iY * iX);
  }
}

// Perform the "+", "-", or "*" operations in a priority queue
void priorityQueueOperation(string sD, priority_queue<int, vector<int>, greater<int> > &myPriorityQueue)
{
    int iX, iY;

  iX = myPriorityQueue.top();
  myPriorityQueue.pop();
  iY = myPriorityQueue.top();
  myPriorityQueue.pop();
  
  if (sD == "+")
  {
    myPriorityQueue.push(iY + iX);
  }
  else if (sD == "-")
  {
    myPriorityQueue.push(iY - iX);
  }
  else if (sD == "*")
  {
    myPriorityQueue.push(iY * iX);
  }
}

// Print the elements in the stack, queue, and priority queue
void showContainers(stack<int> myStack, queue<int> myQueue, priority_queue<int, vector<int>, greater<int> > myPriorityQueue)
{
  while (!myStack.empty())
  {
    cout << myStack.top() << " ";
    myStack.pop();
  }
  
  while (!myQueue.empty())
  {
    cout << myQueue.front() << " ";
    myQueue.pop();
  }

  while (!myPriorityQueue.empty())
  {
    cout << myPriorityQueue.top();
    myPriorityQueue.pop();
  }

  cout << endl;
}

// Empty stack, queue, and priority queue to allow for the next lines of the input to be entered and processed
void emptyContainers(stack<int> &myStack, queue<int> &myQueue, priority_queue<int, vector<int>, greater<int> > &myPriorityQueue)
{
  myStack.pop();
  myQueue.pop();
  myPriorityQueue.pop();
}

int main() 
{
  // Variable declaration
  stack<int> myStack;
  queue<int> myQueue;
  priority_queue<int, vector<int>, greater<int> > myPriorityQueue;
  string sD, sData;
  int iNum;

  getline(cin, sData);

  // Read each line until the #
  while (sData != "#")
  {
    stringstream ss;
    ss << sData;

    // Check each char in string
    while (ss >> sD)
    {
      // If it's a number
      if (sD != "+" && sD != "-" && sD != "*")
      {
        istringstream(sD) >> iNum;
        myStack.push(iNum);
        myQueue.push(iNum);
        myPriorityQueue.push(iNum);
      }
      // If it's an operator
      else
      {
        stackOperation(sD, myStack);
        queueOperation(sD, myQueue);
        priorityQueueOperation(sD, myPriorityQueue);
      }
    }

    // Show results and empty containers
    showContainers(myStack, myQueue, myPriorityQueue);
    emptyContainers(myStack, myQueue, myPriorityQueue);
    getline(cin, sData);
  }

  return 0;
}