//
//  main.cpp
//  PriorityHeap
//
//  Created by Lore Ang on 1/2/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include "Priority.h"
using namespace std;

int main() 
{
  Priority p1(false);
  Priority p2(true);

  cout << "\nHigh priority\n\n";
  p1.push(28);
  p1.print();
  p1.push(21);
  p1.print();
  p1.push(17);
  p1.print();
  p1.push(19);
  p1.print();
  p1.push(5);
  p1.print();
  p1.push(8);
  p1.print();
  cout << "Size: " << p1.size() << endl;
  cout << endl;
  p1.print();
  p1.pop();
  p1.print();
  p1.pop();
  p1.print();
  cout << "Top: ";
  p1.top();
  p1.pop();
  p1.print();
  cout << "Top: ";
  p1.top();
  p1.pop();
  p1.print();
  cout << "Size: " << p1.size();

  cout << "\n\nLow priority\n\n";
  p2.push(28);
  p2.print();
  p2.push(21);
  p2.print();
  p2.push(17);
  p2.print();
  p2.push(19);
  p2.print();
  p2.push(5);
  p2.print();
  p2.push(8);
  p2.print();
  cout << "Size: " << p2.size() << endl;
  cout << endl;
  p2.print();
  cout << "Top: ";
  p2.top();
  p2.pop();
  p2.print();
  cout << "Top: ";
  p2.top();
  p2.pop();
  p2.print();
  p2.pop();
  p2.print();
  p2.pop();
  p2.print();
  cout << "Size: " << p2.size() << endl;
  p2.pop();
  p2.print();
  p2.pop();
  cout << p2.empty() << endl;

  return 0;
}
