//
//  main.cpp
//  queue
//
//  Created by Lore Ang on 19/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<string> miFila;
    
    miFila.push("A");
    miFila.push("B");
    miFila.push("C");
    miFila.push("D");
    miFila.push("E");
    miFila.push("F");

    cout << "Tamano de la fila: " << miFila.getSize() << endl;

    while (!miFila.empty())
    {
        cout << miFila.front() << " ";
        miFila.pop();
    }
    cout << endl;

    cout << "Tamano de la fila: " << miFila.getSize() << endl;
  
  return 0;
}