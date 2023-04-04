#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "A8.h"

int A8power;
int A8water;
int A8population;
int A8money;

A8::A8(){};

A8::~A8(){};

void A8::house(){
    A8water=houseWater;
    A8population=housePopulation;
    A8power=housePower;
    output=output-houseCost; 
};

void A8::shop(){
    A8water=shopWater;
    A8population=shopPopulation;
    A8power=shopPower;
    output=output-shopCost;
};

void A8::factory(){
    A8water=factoryWater;
    A8population=factoryPopulation;
    A8power=factoryPower;
    output=output-factoryCost;
};

void A8::powerplant(){
    A8power=powerplantPower;
    A8water=0;
    A8population=powerplantPopulation;
    output=output-powerplantCost;
};

void A8::waterplant(){
    A8population=waterplantPopulation;
    A8power=0;
    A8water=waterplantWater;
    output=output-waterplantCost;
};

void A8::clear(){
    A8population=0;
    A8power=0;
    A8water=0;
}