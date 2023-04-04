#ifndef __C5_H__
#define __C5_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int C5population;
extern int C5water;
extern int C5power;
extern int C5money;

class C5{
    public:
    C5();
    ~C5();
    //int *C5power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif