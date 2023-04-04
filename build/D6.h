#ifndef __D6_H__
#define __D6_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int D6population;
extern int D6water;
extern int D6power;
extern int D6money;

class D6{
    public:
    D6();
    ~D6();
    //int *D6power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif