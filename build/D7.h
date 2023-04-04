#ifndef __D7_H__
#define __D7_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int D7population;
extern int D7water;
extern int D7power;
extern int D7money;

class D7{
    public:
    D7();
    ~D7();
    //int *D7power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif