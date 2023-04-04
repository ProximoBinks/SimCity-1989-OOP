#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "E7.h"

int E7power;
int E7water;
int E7population;
int E7money;

E7::E7(){};

E7::~E7(){};

void E7::house(){
    E7water=houseWater;
    E7population=housePopulation;
    E7power=housePower;
    output=output-houseCost; 
};

void E7::shop(){
    E7water=shopWater;
    E7population=shopPopulation;
    E7power=shopPower;
    output=output-shopCost;
};

void E7::factory(){
    E7water=factoryWater;
    E7population=factoryPopulation;
    E7power=factoryPower;
    output=output-factoryCost;
};

void E7::powerplant(){
    E7power=powerplantPower;
    E7water=0;
    E7population=powerplantPopulation;
    output=output-powerplantCost;
};

void E7::waterplant(){
    E7population=waterplantPopulation;
    E7power=0;
    E7water=waterplantWater;
    output=output-waterplantCost;
};

void E7::clear(){
    E7population=0;
    E7power=0;
    E7water=0;
}