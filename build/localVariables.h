#ifndef __LOCALVARIABLES_H__
#define __LOCALVARIABLES_H__
#include "raylib.h"
#include <string>

using namespace std;

// house variables
extern int housePopulation;
extern int houseWater;
extern int housePower;
extern int houseCost;

// shop variables
extern int shopPopulation;
extern int shopWater;
extern int shopPower;
extern int shopCost;
extern int shopProduce;

// factory variables
extern int factoryPower;
extern int factoryWater;
extern int factoryPopulation;
extern int factoryCost;
extern int factoryProduce;

// power plant variables
extern int powerplantPopulation;
extern int powerplantPower;
extern int powerplantCost;

// water plant variables
extern int waterplantPopulation;
extern int waterplantWater;
extern int waterplantCost;

class localVariables {
public:
  localVariables();
  ~localVariables();
  // int *a3power= new int;
  void initialise();
};

#endif