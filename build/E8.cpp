#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "E8.h"

int E8power;
int E8water;
int E8population;
int E8money;

E8::E8(){};

E8::~E8(){};

void E8::house(){
    E8water=houseWater;
    E8population=housePopulation;
    E8power=housePower;
    output=output-houseCost; 
};

void E8::shop(){
    E8water=shopWater;
    E8population=shopPopulation;
    E8power=shopPower;
    output=output-shopCost;
};

void E8::factory(){
    E8water=factoryWater;
    E8population=factoryPopulation;
    E8power=factoryPower;
    output=output-factoryCost;
};

void E8::powerplant(){
    E8power=powerplantPower;
    E8water=0;
    E8population=powerplantPopulation;
    output=output-powerplantCost;
};

void E8::waterplant(){
    E8population=waterplantPopulation;
    E8power=0;
    E8water=waterplantWater;
    output=output-waterplantCost;
};

void E8::clear(){
    E8population=0;
    E8power=0;
    E8water=0;
}