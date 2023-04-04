#ifndef __A3_H__
#define __A3_H__
#include "raylib.h"
#include <string>

using namespace std;

//global variables
extern int A3population;
extern int A3water;
extern int A3power;
extern int A3money;

//A3 Class
class A3 {
public:
  A3();
  ~A3();
  //initialise objects 
  void house();
  void shop();
  void factory();
  void powerplant();
  void waterplant();
  void clear();
};

#endif