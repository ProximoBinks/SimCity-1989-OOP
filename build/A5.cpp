#include <iostream>
using namespace std;
#include "A5.h"
#include "globalVariables.h"
#include "localVariables.h"


int A5power;
int A5water;
int A5population;
int A5money;

A5::A5(){};

A5::~A5(){};

void A5::house() {
  A5water = houseWater;
  A5population = housePopulation;
  A5power = housePower;
  output = output - houseCost;
};

void A5::shop() {
  A5water = shopWater;
  A5population = shopPopulation;
  A5power = shopPower;
  output = output - shopCost;
};

void A5::factory() {
  A5water = factoryWater;
  A5population = factoryPopulation;
  A5power = factoryPower;
  output = output - factoryCost;
};

void A5::powerplant() {
  A5power = powerplantPower;
  A5water = 0;
  A5population = powerplantPopulation;
  output = output - powerplantCost;
};

void A5::waterplant() {
  A5population = waterplantPopulation;
  A5power = 0;
  A5water = waterplantWater;
  output = output - waterplantCost;
};

void A5::clear() {
  A5population = 0;
  A5power = 0;
  A5water = 0;
}