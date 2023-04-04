#include <iostream>
using namespace std;
#include "globalVariables.h"
#include "localVariables.h"
#include "E1.h"

int E1power;
int E1water;
int E1population;
int E1money;

E1::E1(){};

E1::~E1(){};

void E1::house(){
    E1water=houseWater;
    E1population=housePopulation;
    E1power=housePower;
    output=output-houseCost; 
};

void E1::shop(){
    E1water=shopWater;
    E1population=shopPopulation;
    E1power=shopPower;
    output=output-shopCost;
};

void E1::factory(){
    E1water=factoryWater;
    E1population=factoryPopulation;
    E1power=factoryPower;
    output=output-factoryCost;
};

void E1::powerplant(){
    E1power=powerplantPower;
    E1water=0;
    E1population=powerplantPopulation;
    output=output-powerplantCost;
};

void E1::waterplant(){
    E1population=waterplantPopulation;
    E1power=0;
    E1water=waterplantWater;
    output=output-waterplantCost;
};

void E1::clear(){
    E1population=0;
    E1power=0;
    E1water=0;
}