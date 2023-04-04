#ifndef __A8_H__
#define __A8_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int A8population;
extern int A8water;
extern int A8power;
extern int A8money;

class A8{
    public:
    A8();
    ~A8();
    //int *A8power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif