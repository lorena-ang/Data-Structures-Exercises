  
//
//  main.cpp
//  icpcScores
//
//  Created by Lore Ang on 12/1/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/*
In ACM ICPC, teams are ranked according to the most problems solved. Teams who solve the same number of problems are ranked by least total time. 
The total time is the sum of the time consumed by each problem solved. The time consumed for a solved problem is the time elapsed from the 
beginning of the contest to the submittal of the accepted run plus 20 penalty minutes for every previously rejected run for that problem 
regardless of submittal time. There is no time consumed for a problem that is not solved. Given the data of the contest, you have to build the final 
score.

Input:
52
UNO
DOS
TRES
CUATRO
CINCO
7
TRES A 15 A
CUATRO A 18 W
CINCO B 20 A
CUATRO A 20 A
CINCO A 25 A
TRES B 32 A
DOS B 38 A

The first line contains two integers  T  (1 <= T <= 20), number of teams,  P  (1<= P <= 10) number of problems.
The next  T  lines are the team’s names (one word per name).
The next line contains an integer  S  (1 <= S <= 1000), number of solutions sent. The next  S  lines contains: the team name, the name of the 
problem (A, B, C, ...), the time when this solutions was sent and the judgment (A = Accepted, W = Wrong Solution).

Output:
1 - CINCO 2 45
2 - TRES 2 47
3 - DOS 1 38
4 - CUATRO 1 40
5 - UNO 0 -
*/

struct Team
{
  // Atributes
  string sName;
  int iTime;
  int iProbs;
  int iArrWr[10];

  // Constructor
  Team()
  {
    sName = ""; 
    iTime = 0;
    iProbs = 0;
    for (int i = 0; i < 10; i++)
    {
      iArrWr[i] = 0;
    }
  }

  // < Operator overload
  bool operator<(Team team2)
  {
    if (iProbs > team2.iProbs)
    {
      return false;
    }
    else if (iProbs < team2.iProbs)
    {
      return true;
    }
    // If the amount of problems answered are the same, check the time
    else if (iProbs == team2.iProbs)
    {
      if (iTime > team2.iTime)
      {
        return true;
      }
      else if (iTime < team2.iTime)
      {
        return false;
      }
    }
    return false;
  }
};

// Greatest to least using bubble sort
void orderScores(Team teams[], int iT)
{
  Team temp;
  bool swapped = false;

  for (int i = 0; i < iT - 1 && !swapped; i++)
  {
    swapped = true;

    for (int j = 0; j < (iT - 1) - i; j++)
    {
      if (teams[j] < teams[j + 1])
      {
        temp = teams[j];
        teams[j] = teams[j+1];
        teams[j + 1] = temp;
        swapped = false;
      }
    }
  }
}

// Print final scores
void showScores(Team teams[], int iT)
{
  for (int i = 0; i < iT; i++)
  {
    cout << i + 1 << " - " << teams[i].sName << " " << teams[i].iProbs << " ";
    if (teams[i].iTime > 0)
    {
      cout << teams[i].iTime << endl;
    }
    else
    {
      cout << "-\n";
    }
  }
}

int main() 
{
  // Variable declaration
  int iT, iP, iS, iTime;
  string sName;
  char cProb;
  char cAc;

  cin >> iT >> iP;

  Team teams[iT];

  for (int i = 0; i < iT; i++)
  {
    cin >> sName;
    teams[i].sName = sName;
  }

  cin >> iS;

  for (int i = 0; i < iS; i++)
  {
    cin >> sName;
    cin >> cProb;
    cin >> iTime;
    cin >> cAc;
    
    for (int j = 0; j < iT; j++)
    {
      // Update data in appropriate team
      if (sName == teams[j].sName)
      {
        // If problem is wrong, add one attempt
        if (cAc == 'W')
        {
          teams[j].iArrWr[cProb - 65] += 1;
        }
        // If problem is correct, count wrong attempts to add total points
        else if (cAc == 'A')
        {
          teams[j].iTime += iTime + (teams[j].iArrWr[cProb - 65] * 20);
          teams[j].iProbs++;
        }
      }
    }
  }

  // Order and show scores
  orderScores(teams, iT);
  showScores(teams, iT);

  return 0;
}
