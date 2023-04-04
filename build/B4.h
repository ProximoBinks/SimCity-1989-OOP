#ifndef __B4_H__
#define __B4_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B4population;
extern int B4water;
extern int B4power;
extern int B4money;

class B4{
    public:
    B4();
    ~B4();
    //int *B4power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif