#ifndef __D8_H__
#define __D8_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int D8population;
extern int D8water;
extern int D8power;
extern int D8money;

class D8{
    public:
    D8();
    ~D8();
    //int *D8power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif