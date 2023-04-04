#ifndef __C8_H__
#define __C8_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int C8population;
extern int C8water;
extern int C8power;
extern int C8money;

class C8{
    public:
    C8();
    ~C8();
    //int *C8power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif