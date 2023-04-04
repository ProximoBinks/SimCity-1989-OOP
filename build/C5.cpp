#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "C5.h"

int C5power;
int C5water;
int C5population;
int C5money;

C5::C5(){};

C5::~C5(){};

void C5::house(){
    C5water=houseWater;
    C5population=housePopulation;
    C5power=housePower;
    output=output-houseCost; 
};

void C5::shop(){
    C5water=shopWater;
    C5population=shopPopulation;
    C5power=shopPower;
    output=output-shopCost;
};

void C5::factory(){
    C5water=factoryWater;
    C5population=factoryPopulation;
    C5power=factoryPower;
    output=output-factoryCost;
};

void C5::powerplant(){
    C5power=powerplantPower;
    C5water=0;
    C5population=powerplantPopulation;
    output=output-powerplantCost;
};

void C5::waterplant(){
    C5population=waterplantPopulation;
    C5power=0;
    C5water=waterplantWater;
    output=output-waterplantCost;
};

void C5::clear(){
    C5population=0;
    C5power=0;
    C5water=0;
}