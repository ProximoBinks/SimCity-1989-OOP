#ifndef __E7_H__
#define __E7_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int E7population;
extern int E7water;
extern int E7power;
extern int E7money;

class E7{
    public:
    E7();
    ~E7();
    //int *E7power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif