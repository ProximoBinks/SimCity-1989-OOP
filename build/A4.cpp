#include <iostream>
using namespace std;
#include "A4.h"
#include "globalVariables.h"
#include "localVariables.h"


int A4power;
int A4water;
int A4population;
int A4money;

A4::A4(){};

A4::~A4(){};

void A4::house() {
  A4water = houseWater;
  A4population = housePopulation;
  A4power = housePower;
  output = output - houseCost;
};

void A4::shop() {
  A4water = shopWater;
  A4population = shopPopulation;
  A4power = shopPower;
  output = output - shopCost;
};

void A4::factory() {
  A4water = factoryWater;
  A4population = factoryPopulation;
  A4power = factoryPower;
  output = output - factoryCost;
};

void A4::powerplant() {
  A4power = powerplantPower;
  A4water = 0;
  A4population = powerplantPopulation;
  output = output - powerplantCost;
};

void A4::waterplant() {
  A4population = waterplantPopulation;
  A4power = 0;
  A4water = waterplantWater;
  output = output - waterplantCost;
};

void A4::clear() {
  A4population = 0;
  A4power = 0;
  A4water = 0;
}