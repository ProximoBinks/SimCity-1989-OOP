#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B5.h"

int B5power;
int B5water;
int B5population;
int B5money;

B5::B5(){};

B5::~B5(){};

void B5::house(){
    B5water=houseWater;
    B5population=housePopulation;
    B5power=housePower;
    output=output-houseCost; 
};

void B5::shop(){
    B5water=shopWater;
    B5population=shopPopulation;
    B5power=shopPower;
    output=output-shopCost;
};

void B5::factory(){
    B5water=factoryWater;
    B5population=factoryPopulation;
    B5power=factoryPower;
    output=output-factoryCost;
};

void B5::powerplant(){
    B5power=powerplantPower;
    B5water=0;
    B5population=powerplantPopulation;
    output=output-powerplantCost;
};

void B5::waterplant(){
    B5population=waterplantPopulation;
    B5power=0;
    B5water=waterplantWater;
    output=output-waterplantCost;
};

void B5::clear(){
    B5population=0;
    B5power=0;
    B5water=0;
}