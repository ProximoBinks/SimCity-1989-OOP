#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "D7.h"

int D7power;
int D7water;
int D7population;
int D7money;

D7::D7(){};

D7::~D7(){};

void D7::house(){
    D7water=houseWater;
    D7population=housePopulation;
    D7power=housePower;
    output=output-houseCost; 
};

void D7::shop(){
    D7water=shopWater;
    D7population=shopPopulation;
    D7power=shopPower;
    output=output-shopCost;
};

void D7::factory(){
    D7water=factoryWater;
    D7population=factoryPopulation;
    D7power=factoryPower;
    output=output-factoryCost;
};

void D7::powerplant(){
    D7power=powerplantPower;
    D7water=0;
    D7population=powerplantPopulation;
    output=output-powerplantCost;
};

void D7::waterplant(){
    D7population=waterplantPopulation;
    D7power=0;
    D7water=waterplantWater;
    output=output-waterplantCost;
};

void D7::clear(){
    D7population=0;
    D7power=0;
    D7water=0;
}