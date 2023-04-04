#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B7.h"

int B7power;
int B7water;
int B7population;
int B7money;

B7::B7(){};

B7::~B7(){};

void B7::house(){
    B7water=houseWater;
    B7population=housePopulation;
    B7power=housePower;
    output=output-houseCost; 
};

void B7::shop(){
    B7water=shopWater;
    B7population=shopPopulation;
    B7power=shopPower;
    output=output-shopCost;
};

void B7::factory(){
    B7water=factoryWater;
    B7population=factoryPopulation;
    B7power=factoryPower;
    output=output-factoryCost;
};

void B7::powerplant(){
    B7power=powerplantPower;
    B7water=0;
    B7population=powerplantPopulation;
    output=output-powerplantCost;
};

void B7::waterplant(){
    B7population=waterplantPopulation;
    B7power=0;
    B7water=waterplantWater;
    output=output-waterplantCost;
};

void B7::clear(){
    B7population=0;
    B7power=0;
    B7water=0;
}