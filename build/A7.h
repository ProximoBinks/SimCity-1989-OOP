#ifndef __A7_H__
#define __A7_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int A7population;
extern int A7water;
extern int A7power;
extern int A7money;

class A7{
    public:
    A7();
    ~A7();
    //int *A7power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif