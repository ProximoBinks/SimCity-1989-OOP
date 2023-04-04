#include <iostream>
using namespace std;
#include "A3.h"
#include "globalVariables.h"
#include "localVariables.h"

//define variables 
int A3power;
int A3water;
int A3population;
int A3money;

//default constructor
A3::A3(){};

A3::~A3(){};


//objects set local A3 variables to the building type
void A3::house() {
  A3water = houseWater;
  A3population = housePopulation;
  A3power = housePower;
  output = output - houseCost;
};

void A3::shop() {
  A3water = shopWater;
  A3population = shopPopulation;
  A3power = shopPower;
  output = output - shopCost;
};

void A3::factory() {
  A3water = factoryWater;
  A3population = factoryPopulation;
  A3power = factoryPower;
  output = output - factoryCost;
};

void A3::powerplant() {
  A3power = powerplantPower;
  A3water = 0;
  A3population = powerplantPopulation;
  output = output - powerplantCost;
};

void A3::waterplant() {
  A3population = waterplantPopulation;
  A3power = 0;
  A3water = waterplantWater;
  output = output - waterplantCost;
};

//Clear building from grid
void A3::clear() {
  A3population = 0;
  A3power = 0;
  A3water = 0;
}