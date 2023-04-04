#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "D6.h"

int D6power;
int D6water;
int D6population;
int D6money;

D6::D6(){};

D6::~D6(){};

void D6::house(){
    D6water=houseWater;
    D6population=housePopulation;
    D6power=housePower;
    output=output-houseCost; 
};

void D6::shop(){
    D6water=shopWater;
    D6population=shopPopulation;
    D6power=shopPower;
    output=output-shopCost;
};

void D6::factory(){
    D6water=factoryWater;
    D6population=factoryPopulation;
    D6power=factoryPower;
    output=output-factoryCost;
};

void D6::powerplant(){
    D6power=powerplantPower;
    D6water=0;
    D6population=powerplantPopulation;
    output=output-powerplantCost;
};

void D6::waterplant(){
    D6population=waterplantPopulation;
    D6power=0;
    D6water=waterplantWater;
    output=output-waterplantCost;
};

void D6::clear(){
    D6population=0;
    D6power=0;
    D6water=0;
}