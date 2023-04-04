#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B4.h"

int B4power;
int B4water;
int B4population;
int B4money;

B4::B4(){};

B4::~B4(){};

void B4::house(){
    B4water=houseWater;
    B4population=housePopulation;
    B4power=housePower;
    output=output-houseCost; 
};

void B4::shop(){
    B4water=shopWater;
    B4population=shopPopulation;
    B4power=shopPower;
    output=output-shopCost;
};

void B4::factory(){
    B4water=factoryWater;
    B4population=factoryPopulation;
    B4power=factoryPower;
    output=output-factoryCost;
};

void B4::powerplant(){
    B4power=powerplantPower;
    B4water=0;
    B4population=powerplantPopulation;
    output=output-powerplantCost;
};

void B4::waterplant(){
    B4population=waterplantPopulation;
    B4power=0;
    B4water=waterplantWater;
    output=output-waterplantCost;
};

void B4::clear(){
    B4population=0;
    B4power=0;
    B4water=0;
}