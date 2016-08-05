#include "AB/common.hpp"

WF_MSW_DISABLE(MSW_STL)
#include <iostream>
#include <limits>

#include<vector>
#include<map>
#include <algorithm>
#include <string>
#include <sstream>
WF_MSW_RESTORE()

#include "AB/logger.hpp"

using namespace std;

int main()
{

  vector<int> lVector;
  lVector.push_back(0);
  lVector.push_back(1);
  lVector.push_back(2);

  map<int, string> lMap;
  for (vector<int>::iterator it = lVector.begin(); it != lVector.end(); ++it)
  {
    int& lValue = *it;
    //lMap[lValue] = "Element has value " + lValue;
    stringstream aux;
    aux << "Element has value ";
    aux << lValue;

    const string lStringValue = aux.str();

    lMap.insert(make_pair(lValue, lStringValue));
  }

  const map<int, string>& lMapReadOnly = lMap;
  for (map<int, string>::const_iterator it = lMapReadOnly.begin(); it != lMapReadOnly.end(); ++it)
  {
    cout << it->first << " " << it->second << endl;
  }



  std::cin.get();
}