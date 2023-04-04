#ifndef __B6_H__
#define __B6_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B6population;
extern int B6water;
extern int B6power;
extern int B6money;

class B6{
    public:
    B6();
    ~B6();
    //int *B6power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif