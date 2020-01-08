//
//  main.cpp
//  Sudoku Check
//
//  Created by Lore Ang on 7/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

/*
Sudoku is a game in a 9x9 matrix with numbers from 1 to 9, where there should only be just one of these numbers in: - each row - each column - each 3x3 matrix. An example of a complete game is: Given a group of numbers, print YES if is a correct SUDOKU game, or NO if other case.

Example:
Input matrix elements:
4 3 5 2 6 9 7 8 1
6 8 2 5 7 1 4 9 3
1 9 7 8 3 4 5 6 2
8 2 6 1 9 5 3 4 7
3 7 4 6 8 2 9 1 5
9 5 1 7 4 3 6 2 8
5 1 9 3 2 6 8 7 4
2 4 8 9 5 7 1 3 6
7 6 3 4 1 8 2 5 9

Output:
YES
*/

// Check if there are wrong numbers in any row or column
bool checkRowCol(int iMat[9][9], int iArrNum[9])
{
  int iArrRows[9], iArrCols[9];

  // Store values of each row and column in arrays
  for (int iR = 0, iC2 = 0; iR < 9; iR++, iC2++)
  {
    for (int iC = 0, iR2 = 0; iC < 9; iC++, iR2++)
    {
      iArrRows[iC] = iMat[iR][iC];
      iArrCols[iR2] = iMat[iR2][iC2];
    }

    // Order arrays from smallest to greatest
    sort(iArrRows, iArrRows + 9);
    sort(iArrCols, iArrCols + 9);

    // Compare ordered arrays to array containing all numbers from 1-9
    for (int i = 0; i < 9; i++)
    {
      if (iArrRows[i] != iArrNum[i] || iArrCols[i] != iArrNum[i])
      {
        return false;
      }
    }
  }

  return true;
}

// Check if there are wrong numbers in each 3x3 square
bool checkSquares(int iMat[9][9], int iArrNum[9], int iN)
{
  int iArrSquare[9], r, c;
  int iX = 0;

  // Rows and columns where each square begins
  switch (iN)
  {
    case 1:
      r = 0;
      c = 0;
      break;
    case 2:
      r = 0;
      c = 3;
      break;
    case 3:
      r = 0;
      c = 6;
      break;
    case 4:
      r = 3;
      c = 0;
      break;
    case 5:
      r = 3;
      c = 3;
      break;
    case 6:
      r = 3;
      c = 6;
      break;
    case 7:
      r = 6;
      c = 0;
      break;
    case 8:
      r = 6;
      c = 3;
      break;
    case 9:
      r = 6;
      c = 6;
  }

  // Store values of each element in 3x3 square in an array
  for (int iR = r; iR < r + 3; iR++)
  {
    for (int iC = c; iC < c + 3; iC++)
    {
      iArrSquare[iX] = iMat[iR][iC];
      iX++;
    }
  }

  // Order array from smallest to greatest
  sort(iArrSquare, iArrSquare + 9);

  // Compare ordered array to array containing all numbers from 1-9
  for (int i = 0; i < 9; i++)
  {
    if (iArrSquare[i] != iArrNum[i])
    {
      return false;
    }
  }

  return true;
}

int main() 
{
  // Variable declaration
  int iMat[9][9], iN;
  int iArrNum[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  bool bValid = true;

  // Enter input
  for (int iR = 0; iR < 9; iR++)
  {
    for (int iC = 0; iC < 9; iC++)
    {
      cin >> iMat[iR][iC];
    }
  }

  // Check each of the nine 3x3 squares
  for (int i = 1; i <= 9 && bValid; i++)
  {
    if (!checkSquares(iMat, iArrNum, i))
    {
      bValid = false;
    }
  }

  // If an element is wrong in a row, column or square
  if (!checkRowCol(iMat, iArrNum) || !bValid)
  {
    cout << "NO\n";
  }
  else
  {
    cout << "YES\n";
  }

  return 0;
}