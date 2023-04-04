#ifndef __C6_H__
#define __C6_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int C6population;
extern int C6water;
extern int C6power;
extern int C6money;

class C6{
    public:
    C6();
    ~C6();
    //int *C6power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif