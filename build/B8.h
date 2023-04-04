#ifndef __B8_H__
#define __B8_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int B8population;
extern int B8water;
extern int B8power;
extern int B8money;

class B8{
    public:
    B8();
    ~B8();
    //int *B8power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif