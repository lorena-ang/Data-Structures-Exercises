  
//
//  main.cpp
//  BST
//
//  Created by Lore Ang on 23/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
using namespace std;
#include "BST.h"

int main() 
{
  BST tree;
	tree.add(10);
	tree.add(5);
	tree.add(2);
	tree.add(3);
	tree.add(8);
	tree.add(20);
	tree.add(17);
	tree.add(12);
	tree.add(19);
	tree.add(18);
	tree.add(30);
	tree.add(25);

	cout << "preOrder: ";
	tree.print(1);
	cout << "inOrder: ";
	tree.print(2);
	cout << "postOrder: ";
	tree.print(3);
  	cout << "printLeaves: ";
  	tree.print(4);
  	cout << "nivelXnivel: ";
  	tree.print(5);

	cout << "Search(20): " << tree.search(20) << endl;
	cout << "Search(25): " << tree.search(25) << endl;
	cout << "Search(99): " << tree.search(99) << endl;

	tree.remove(25);
	cout << "Search(25): " << tree.search(25) << endl;

  	cout << "\nAmount of elements: " << tree.count() << endl;
  	cout << "Height: " << tree.height() << endl;

  	cout << "Ancestors of 17: ";
  	tree.ancestors(17);

  	cout << "Level of 2: " << tree.whatLevelamI(2) << endl;

	return 0;
}