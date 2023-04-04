#ifndef __C7_H__
#define __C7_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int C7population;
extern int C7water;
extern int C7power;
extern int C7money;

class C7{
    public:
    C7();
    ~C7();
    //int *C7power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif