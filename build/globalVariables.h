#ifndef __GLOBALVARIABLES_H__
#define __GLOBALVARIABLES_H__
#include "raylib.h"
#include "squareheaders.h"
#include <string>

using namespace std;
// global variables
extern int intWater;
extern int intMoney;
extern int intPopulation;
extern int intPower;
extern string stringPower;
extern string stringPopulation;
extern string stringWater;
extern string stringMoney;
extern int output;
extern int globalPower;
extern int globalWater;
// counts number of buildings
extern int noShop;
extern int noHouse;
extern int noFactory;
extern int noWaterplant;
extern int noPowerplant;
extern int noShop;
// global variables class
class globalVariables {
public:
  globalVariables();
  ~globalVariables();
  // object initialisation
  void initialise();
  int population();
  int water();
  int power();
  int money();
  char const *charMoney;
  char const *charPower;
  char const *charPopulation;
  char const *charWater;
};

#endif