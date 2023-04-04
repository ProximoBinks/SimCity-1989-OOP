#ifndef __A6_H__
#define __A6_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int A6population;
extern int A6water;
extern int A6power;
extern int A6money;

class A6{
    public:
    A6();
    ~A6();
    //int *A6power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif