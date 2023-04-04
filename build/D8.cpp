#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "D8.h"

int D8power;
int D8water;
int D8population;
int D8money;

D8::D8(){};

D8::~D8(){};

void D8::house(){
    D8water=houseWater;
    D8population=housePopulation;
    D8power=housePower;
    output=output-houseCost; 
};

void D8::shop(){
    D8water=shopWater;
    D8population=shopPopulation;
    D8power=shopPower;
    output=output-shopCost;
};

void D8::factory(){
    D8water=factoryWater;
    D8population=factoryPopulation;
    D8power=factoryPower;
    output=output-factoryCost;
};

void D8::powerplant(){
    D8power=powerplantPower;
    D8water=0;
    D8population=powerplantPopulation;
    output=output-powerplantCost;
};

void D8::waterplant(){
    D8population=waterplantPopulation;
    D8power=0;
    D8water=waterplantWater;
    output=output-waterplantCost;
};

void D8::clear(){
    D8population=0;
    D8power=0;
    D8water=0;
}