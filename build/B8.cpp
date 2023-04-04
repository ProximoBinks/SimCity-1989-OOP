#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B8.h"

int B8power;
int B8water;
int B8population;
int B8money;

B8::B8(){};

B8::~B8(){};

void B8::house(){
    B8water=houseWater;
    B8population=housePopulation;
    B8power=housePower;
    output=output-houseCost; 
};

void B8::shop(){
    B8water=shopWater;
    B8population=shopPopulation;
    B8power=shopPower;
    output=output-shopCost;
};

void B8::factory(){
    B8water=factoryWater;
    B8population=factoryPopulation;
    B8power=factoryPower;
    output=output-factoryCost;
};

void B8::powerplant(){
    B8power=powerplantPower;
    B8water=0;
    B8population=powerplantPopulation;
    output=output-powerplantCost;
};

void B8::waterplant(){
    B8population=waterplantPopulation;
    B8power=0;
    B8water=waterplantWater;
    output=output-waterplantCost;
};

void B8::clear(){
    B8population=0;
    B8power=0;
    B8water=0;
}