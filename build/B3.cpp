#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "B3.h"

int B3power;
int B3water;
int B3population;
int B3money;

B3::B3(){};

B3::~B3(){};

void B3::house(){
    B3water=houseWater;
    B3population=housePopulation;
    B3power=housePower;
    output=output-houseCost; 
};

void B3::shop(){
    B3water=shopWater;
    B3population=shopPopulation;
    B3power=shopPower;
    output=output-shopCost;
};

void B3::factory(){
    B3water=factoryWater;
    B3population=factoryPopulation;
    B3power=factoryPower;
    output=output-factoryCost;
};

void B3::powerplant(){
    B3power=powerplantPower;
    B3water=0;
    B3population=powerplantPopulation;
    output=output-powerplantCost;
};

void B3::waterplant(){
    B3population=waterplantPopulation;
    B3power=0;
    B3water=waterplantWater;
    output=output-waterplantCost;
};

void B3::clear(){
    B3population=0;
    B3power=0;
    B3water=0;
}