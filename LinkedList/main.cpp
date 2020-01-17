//
//  main.cpp
//  linkedLists
//
//  Created by Lore Ang on 13/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() 
{
  cout << "Prueba 1\n";
  LinkedList<int> myList1;
  myList1.addFirst(3);
  myList1.addFirst(2);
  myList1.addFirst(1);
  myList1.addLast(5);
  myList1.print();
  myList1.add(4, 3);
  myList1.print();
  cout << myList1.getSize() << " " << myList1.isEmpty() << endl;
  myList1.print();

  cout << "\nPrueba 2\n"; 
  myList1.print();
  cout << myList1.get(2) << " " << myList1.set(6, 4) << endl;
  myList1.print();
  myList1.add(5, 5);
  myList1.change(5, 4);
  myList1.print();

  cout << "\nPrueba 3\n";
  myList1.deleteLast();
  LinkedList<int> myList2(myList1);
  myList2.print();
  myList2.deleteFirst();
  myList2.print();
  myList2.reverse();
  myList2.print();
  myList2.del(1);
  myList2.print();

  cout << "\nPrueba 4\n";
  LinkedList<int> myList3;
  LinkedList<int> myList4;
  myList3.addFirst(4);
  myList3.addFirst(3);
  myList3.addFirst(2);
  myList3.addFirst(1);
  myList3.addLast(5);
  myList1.print();
  myList3.print();
  cout << (myList1 == myList3) << endl;

  cout << "\nPrueba 5\n";
  myList4.print();
  myList4 = myList3;
  myList3.print();
  myList4.print();
  myList4 += 6;
  myList4.print();
  LinkedList<int> myList5;
  myList5.addFirst(1);
  myList5.print();
  myList5 += myList4;
  myList5.print();
  myList5.deleteAll();
  myList5.print();

  cout << "Prueba 6\n";
  LinkedList<char> myList6;
  myList6.addFirst('C');
  myList6.addFirst('B');
  myList6.addFirst('A');
  myList6.print();
  myList6.shift(1);
  myList6.print();
  myList6.shift(-1);
  myList6.print();

  return 0;
}
