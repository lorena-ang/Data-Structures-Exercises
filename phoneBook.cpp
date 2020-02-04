//
//  main.cpp
//  phoneBook.cpp
//
//  Created by Lore Ang on 1/2/2020.
//  Copyright © 2020 Lore Ang. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool keyExist(int iNum, string &sName, map<int, string> myMap)
{
  map<int, string>::iterator it = myMap.find(iNum);

  if (it != myMap.end())
  {
    sName = it->second;
    return true;
  }
  else
  {
    return false;
  }
}

int main() 
{
  int iNum, iQueries;
  string sName, sQuery;
  map<int, string> myMap;
  vector<string> outputs;

  cin >> iQueries;

  for (int i = 0; i < iQueries; i++)
  {
    sName = "";
    
    cin >> sQuery;
    
    if (sQuery == "add")
    {
      cin >> iNum >> sName;
      myMap[iNum] = sName;
    }
    else if (sQuery == "find")
    {
      cin >> iNum;
      if (keyExist(iNum, sName, myMap))
      {
        outputs.push_back(sName);
      }
      else
      {
        outputs.push_back("not found");
      }
    }
    else if (sQuery == "del")
    {
      cin >> iNum;
      if (keyExist(iNum, sName, myMap))
      {
        myMap.erase(iNum);
      }
    }
  }

  for (int i = 0; i < outputs.size(); i++)
  {
    cout << outputs[i] << endl;
  }
  
  return 0;
}