#ifndef __A4_H__
#define __A4_H__
#include "raylib.h"
#include <string>

using namespace std;

extern int A4population;
extern int A4water;
extern int A4power;
extern int A4money;

class A4 {
public:
  A4();
  ~A4();
  // int *A4power= new int;
  void house();
  void shop();
  void factory();
  void powerplant();
  void waterplant();
  void clear();
};

#endif