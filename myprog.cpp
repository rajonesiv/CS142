//**********************************************************************
// Program 0 - The Welcome Program
// Author: [Andrew Jones]
// Date: Wednesday, September 2nd, 2015
//
// This program asks the user his or her name, greets them by name,
// and welcomes them to CS142, the best course ever.
//
//**********************************************************************
#include <iostream>

using namespace std;

int main()
{
  char name[30];

  cout << "What is your name? ";
  cin >> name;
  cout << "Hello " << name << "." << endl;
  cout << "Welcome to CS142, the greatest class ever!!!" << endl;

  return 0;
}

