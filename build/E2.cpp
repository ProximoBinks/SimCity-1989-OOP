#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "E2.h"

int E2power;
int E2water;
int E2population;
int E2money;

E2::E2(){};

E2::~E2(){};

void E2::house(){
    E2water=houseWater;
    E2population=housePopulation;
    E2power=housePower;
    output=output-houseCost; 
};

void E2::shop(){
    E2water=shopWater;
    E2population=shopPopulation;
    E2power=shopPower;
    output=output-shopCost;
};

void E2::factory(){
    E2water=factoryWater;
    E2population=factoryPopulation;
    E2power=factoryPower;
    output=output-factoryCost;
};

void E2::powerplant(){
    E2power=powerplantPower;
    E2water=0;
    E2population=powerplantPopulation;
    output=output-powerplantCost;
};

void E2::waterplant(){
    E2population=waterplantPopulation;
    E2power=0;
    E2water=waterplantWater;
    output=output-waterplantCost;
};

void E2::clear(){
    E2population=0;
    E2power=0;
    E2water=0;
}