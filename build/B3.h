#ifndef __B3_H__
#define __B3_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B3population;
extern int B3water;
extern int B3power;
extern int B3money;

class B3{
    public:
    B3();
    ~B3();
    //int *B3power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif