#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "A6.h"

int A6power;
int A6water;
int A6population;
int A6money;

A6::A6(){};

A6::~A6(){};

void A6::house(){
    A6water=houseWater;
    A6population=housePopulation;
    A6power=housePower;
    output=output-houseCost; 
};

void A6::shop(){
    A6water=shopWater;
    A6population=shopPopulation;
    A6power=shopPower;
    output=output-shopCost;
};

void A6::factory(){
    A6water=factoryWater;
    A6population=factoryPopulation;
    A6power=factoryPower;
    output=output-factoryCost;
};

void A6::powerplant(){
    A6power=powerplantPower;
    A6water=0;
    A6population=powerplantPopulation;
    output=output-powerplantCost;
};

void A6::waterplant(){
    A6population=waterplantPopulation;
    A6power=0;
    A6water=waterplantWater;
    output=output-waterplantCost;
};

void A6::clear(){
    A6population=0;
    A6power=0;
    A6water=0;
}