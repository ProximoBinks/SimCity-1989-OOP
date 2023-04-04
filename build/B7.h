#ifndef __B7_H__
#define __B7_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B7population;
extern int B7water;
extern int B7power;
extern int B7money;

class B7{
    public:
    B7();
    ~B7();
    //int *B7power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif