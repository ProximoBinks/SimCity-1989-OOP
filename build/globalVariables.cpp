#include <iostream>
using namespace std;
#include "squareheaders.h"
#include "StatusBar.h"
#include "globalVariables.h"
#include "localVariables.h"

//default constructor
globalVariables::globalVariables(){};

globalVariables::~globalVariables(){};

int output = 10000;
int globalPower = 0;
int globalWater = 0;
int noHouse = 0;
int noFactory = 0;
int noWaterplant = 0;
int noPowerplant = 0;
int noShop = 0;

void globalVariables::initialise() {
  intPopulation = 0;
  intMoney = 10000;
  stringPower = "";
  stringPopulation = "";
  stringWater = "";
  stringMoney = "";
}

int globalVariables::population() {
  intPopulation = A3population + A4population + A5population + A6population +
                  A7population + A8population + B3population + B4population +
                  B5population + B6population + B7population + B8population +
                  C5population + C6population + C7population + C8population +
                  D6population + D7population + D8population + E1population +
                  E2population + E7population + E8population;
  return intPopulation;
}

int globalVariables::power() {
  intPower = globalPower + A3power + A4power + A5power + A6power + A7power +
             A8power + B3power + B4power + B5power + B6power + B7power +
             B8power + C5power + C6power + C7power + C8power + D6power +
             D7power + D8power + E1power + E2power + E7power + E8power;
  return intPower;
}

int globalVariables::water() {
  intWater = globalWater + A3water + A4water + A5water + A6water + A7water +
             A8water + B3water + B4water + B3water + B5water + B6water +
             B7water + B8water + C5water + C6water + C7water + C8water +
             D6water + D7water + D8water + E1water + E2water + E7water +
             E8water;
  return intWater;
}

int globalVariables::money() { return output; }