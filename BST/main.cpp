//
//  main.cpp
//  BST
//
//  Created by Lore Ang on 23/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
#include "BST.h"

int main() 
{
  BST tree, tree2, tree4;
  queue<int> myQueue;
  stack<int> myStack;
  vector<int> myVector;

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

	cout << "\nSearch(20): " << tree.search(20) << endl;
	cout << "Search(25): " << tree.search(25) << endl;
	cout << "Search(99): " << tree.search(99) << endl;

	tree.remove(25);
	cout << "Search(25): " << tree.search(25) << endl;

  cout << "\nAmount of elements: " << tree.count() << endl;
  cout << "Height: " << tree.height() << endl;

  cout << "Ancestors of 17: ";
  tree.ancestors(17);
  cout << "Level of 2: " << tree.whatLevelamI(2) << endl;

  cout << "\ninOrder: ";
  tree.print(2);
  myQueue = tree.toQueue();
  cout << "To queue: ";
  int size = myQueue.size();
  for (int i = 0; i < size; i++)
  {
    cout << myQueue.front() << " ";
    myQueue.pop();
  }
  cout << endl << endl;

  tree2.add(10);
	tree2.add(5);
	tree2.add(2);
  tree2.add(30);
	tree2.add(3);
	tree2.add(8);
	tree2.add(20);
	tree2.add(17);
	tree2.add(12);
	tree2.add(19);
	tree2.add(18);
	tree2.add(30);
  cout << "preOrder tree: ";
  tree.print(1);
  cout << "preOrder tree2: ";
  tree2.print(1);
  if (tree == tree2)
  {
    cout << "tree and tree2 are equal\n";
  }
  else
  {
    cout << "tree and tree2 are different\n";
  }

  cout << "Original tree: ";
  tree.print(1);
  BST tree3(tree);
  cout << "Copied tree: ";
  tree3.print(1);

  tree4.add(10);
	tree4.add(5);
	tree4.add(2);
  tree4.add(30);
	tree4.add(3);
  tree4.add(35);
  tree4.add(20);
  cout << "\npreOrder tree: ";
  tree4.print(1);
  cout << "Maximum width: " << tree4.maxWidth() << endl;
  cout << "Nearest relative of 35 and 30: " << tree4.nearestRelative(35, 30);
  cout << "\nNearest relative of 35 and 30: " << tree4.nearestRelative2(35, 30);

	return 0;
}