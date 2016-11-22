#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>
using namespace std;

/*
 *  This class is a dummy class to help show how to
 *  break our class into an interface and implementation
 *  file. It will set a member variable to 1 on initialization
 *  and output it using the Output() function.
 */
class MyClass {
 public:
  /*
   * Constructor
   * Initialize our member variable num_ to 0
   */
  MyClass();
  /*
   * Output our member variable using cout
   */
  void Output();
 private:
  int num_;
};

#endif