#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "A7.h"

int A7power;
int A7water;
int A7population;
int A7money;

A7::A7(){};

A7::~A7(){};

void A7::house(){
    A7water=houseWater;
    A7population=housePopulation;
    A7power=housePower;
    output=output-houseCost; 
};

void A7::shop(){
    A7water=shopWater;
    A7population=shopPopulation;
    A7power=shopPower;
    output=output-shopCost;
};

void A7::factory(){
    A7water=factoryWater;
    A7population=factoryPopulation;
    A7power=factoryPower;
    output=output-factoryCost;
};

void A7::powerplant(){
    A7power=powerplantPower;
    A7water=0;
    A7population=powerplantPopulation;
    output=output-powerplantCost;
};

void A7::waterplant(){
    A7population=waterplantPopulation;
    A7power=0;
    A7water=waterplantWater;
    output=output-waterplantCost;
};

void A7::clear(){
    A7population=0;
    A7power=0;
    A7water=0;
}