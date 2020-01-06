//
//  main.cpp
//  Turning Matrix
//
//  Created by Lore Ang on 6/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
using namespace std;

/*
Write a program that, given a 4 x 4 square matrix of numbers read from the keyboard, generates a new matrix with "n" turns clockwise where n is an integer.

Example
Input "n" and matrix elements:
5
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

Output rotated matrix:
13 9 5 1
14 10 6 2
15 11 7 3
16 12 8 4
*/

// Print matrix
void printMat(int iMat[4][4])
{
  for (int iR = 0; iR < 4; iR++)
  {
    for (int iC = 0; iC < 4; iC++)
    {
      if (iC != 3)
      {
        cout << iMat[iR][iC] << " ";
      }
      else
      {
        cout << iMat[iR][iC];
      }
    }
    cout << endl;
  }
}

int main() {
  
  // Variable declaration
  int iN;
  int iMat[4][4], iMatTemp[4][4];

  // Input data
  cin >> iN;
  for (int iR = 0; iR < 4; iR++)
  {
    for (int iC = 0; iC < 4; iC++)
    {
      cin >> iMat[iR][iC];
    }
  }
  cout << endl;

  // Matrix stays the same
  if (iN % 4 == 0) // -4, 0, 4, 8, 12...
  {
    printMat(iMat);
  }
  // Matriz turns 2 times - top is now at bottom
  else if (iN % 2 == 0) // -2, 2, 6, 10, 14...
  {
    for (int iR = 0, iR2 = 3; iR < 2; iR++, iR2--)
    {
      for (int iC = 0, iC2 = 3; iC < 4; iC++, iC2--)
      {
        iMatTemp[iR2][iC2] = iMat[iR][iC];
        iMatTemp[iR][iC] = iMat[iR2][iC2];
      }
    }
    printMat(iMatTemp);
  }
  // Matrix turns to the right
  else if ((iN - 1) % 4 == 0) // -3, 1, 5, 9, 13...
  {
    for (int iR = 0; iR < 4; iR++)
    {
      for (int iC = 0, iC2 = 3; iC2 > 1; iC++, iC2--)
      {
        iMatTemp[iR][iC2] = iMat[iC][iR];
        iMatTemp[iR][iC] = iMat[iC2][iR];
      }
    }
    printMat(iMatTemp);
  }
  // Matriz turns to the left
  else if ((iN + 1) % 4 == 0) // -1, 3, 7, 11, 15...
  {
    for (int iC = 0; iC < 4; iC++)
    {
      for (int iR = 0, iR2 = 3; iR2 > 1; iR++, iR2--)
      {
        iMatTemp[iR2][iC] = iMat[iC][iR];
        iMatTemp[iR][iC] = iMat[iC][iR2];
      }
    }
    printMat(iMatTemp);
  }

  return 0;
}