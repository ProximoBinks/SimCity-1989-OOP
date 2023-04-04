#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "C6.h"

int C6power;
int C6water;
int C6population;
int C6money;

C6::C6(){};

C6::~C6(){};

void C6::house(){
    C6water=houseWater;
    C6population=housePopulation;
    C6power=housePower;
    output=output-houseCost; 
};

void C6::shop(){
    C6water=shopWater;
    C6population=shopPopulation;
    C6power=shopPower;
    output=output-shopCost;
};

void C6::factory(){
    C6water=factoryWater;
    C6population=factoryPopulation;
    C6power=factoryPower;
    output=output-factoryCost;
};

void C6::powerplant(){
    C6power=powerplantPower;
    C6water=0;
    C6population=powerplantPopulation;
    output=output-powerplantCost;
};

void C6::waterplant(){
    C6population=waterplantPopulation;
    C6power=0;
    C6water=waterplantWater;
    output=output-waterplantCost;
};

void C6::clear(){
    C6population=0;
    C6power=0;
    C6water=0;
}