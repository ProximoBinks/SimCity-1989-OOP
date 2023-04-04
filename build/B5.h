#ifndef __B5_H__
#define __B5_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B5population;
extern int B5water;
extern int B5power;
extern int B5money;

class B5{
    public:
    B5();
    ~B5();
    //int *B5power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif