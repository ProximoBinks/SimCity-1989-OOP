#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "C7.h"

int C7power;
int C7water;
int C7population;
int C7money;

C7::C7(){};

C7::~C7(){};

void C7::house(){
    C7water=houseWater;
    C7population=housePopulation;
    C7power=housePower;
    output=output-houseCost; 
};

void C7::shop(){
    C7water=shopWater;
    C7population=shopPopulation;
    C7power=shopPower;
    output=output-shopCost;
};

void C7::factory(){
    C7water=factoryWater;
    C7population=factoryPopulation;
    C7power=factoryPower;
    output=output-factoryCost;
};

void C7::powerplant(){
    C7power=powerplantPower;
    C7water=0;
    C7population=powerplantPopulation;
    output=output-powerplantCost;
};

void C7::waterplant(){
    C7population=waterplantPopulation;
    C7power=0;
    C7water=waterplantWater;
    output=output-waterplantCost;
};

void C7::clear(){
    C7population=0;
    C7power=0;
    C7water=0;
}