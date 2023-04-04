#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"


// shop variables
int shopPower;
int shopWater;
int shopPopulation;
int shopCost;
int shopProduce;

// house variables
int housePower;
int houseWater;
int housePopulation;
int houseCost;

// factory variables
int factoryPower;
int factoryWater;
int factoryPopulation;
int factoryCost;
int factoryProduce;

// power plant variables
int powerplantPopulation;
int powerplantPower;
int powerplantCost;

// water plant variables
int waterplantPopulation;
int waterplantWater;
int waterplantCost;

localVariables::localVariables(){};

localVariables::~localVariables(){};
void localVariables::initialise() {
  // house initilisation
  housePopulation = 5;
  houseWater = 0;
  housePower = 0;
  houseCost = 1500;

  // shop initilisation
  shopPopulation = 0;
  shopWater = 0;
  shopPower = 0;
  shopCost = 2500;
  shopProduce = 300;

  // power plant initilisation
  powerplantPower = 200;
  powerplantPopulation = 50;
  powerplantCost = 3000;

  // water plant initilisation
  waterplantWater = 200;
  waterplantPopulation = 50;
  waterplantCost = 3000;

  // factory initilisation
  factoryCost = 3000;
  factoryPopulation = 100;
  factoryWater = -50;
  factoryPower = -50;
  factoryProduce = 200;
};
