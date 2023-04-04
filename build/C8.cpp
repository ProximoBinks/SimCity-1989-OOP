#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "C8.h"

int C8power;
int C8water;
int C8population;
int C8money;

C8::C8(){};

C8::~C8(){};

void C8::house(){
    C8water=houseWater;
    C8population=housePopulation;
    C8power=housePower;
    output=output-houseCost; 
};

void C8::shop(){
    C8water=shopWater;
    C8population=shopPopulation;
    C8power=shopPower;
    output=output-shopCost;
};

void C8::factory(){
    C8water=factoryWater;
    C8population=factoryPopulation;
    C8power=factoryPower;
    output=output-factoryCost;
};

void C8::powerplant(){
    C8power=powerplantPower;
    C8water=0;
    C8population=powerplantPopulation;
    output=output-powerplantCost;
};

void C8::waterplant(){
    C8population=waterplantPopulation;
    C8power=0;
    C8water=waterplantWater;
    output=output-waterplantCost;
};

void C8::clear(){
    C8population=0;
    C8power=0;
    C8water=0;
}