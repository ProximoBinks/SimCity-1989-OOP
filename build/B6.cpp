#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B6.h"

int B6power;
int B6water;
int B6population;
int B6money;

B6::B6(){};

B6::~B6(){};

void B6::house(){
    B6water=houseWater;
    B6population=housePopulation;
    B6power=housePower;
    output=output-houseCost; 
};

void B6::shop(){
    B6water=shopWater;
    B6population=shopPopulation;
    B6power=shopPower;
    output=output-shopCost;
};

void B6::factory(){
    B6water=factoryWater;
    B6population=factoryPopulation;
    B6power=factoryPower;
    output=output-factoryCost;
};

void B6::powerplant(){
    B6power=powerplantPower;
    B6water=0;
    B6population=powerplantPopulation;
    output=output-powerplantCost;
};

void B6::waterplant(){
    B6population=waterplantPopulation;
    B6power=0;
    B6water=waterplantWater;
    output=output-waterplantCost;
};

void B6::clear(){
    B6population=0;
    B6power=0;
    B6water=0;
}