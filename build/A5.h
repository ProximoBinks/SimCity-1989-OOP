#ifndef __A5_H__
#define __A5_H__
#include "raylib.h"
#include <string>

using namespace std;

extern int A5population;
extern int A5water;
extern int A5power;
extern int A5money;

class A5 {
public:
  A5();
  ~A5();
  // int *A5power= new int;
  void house();
  void shop();
  void factory();
  void powerplant();
  void waterplant();
  void clear();
};

#endif