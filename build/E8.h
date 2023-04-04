#ifndef __E8_H__
#define __E8_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int E8population;
extern int E8water;
extern int E8power;
extern int E8money;

class E8{
    public:
    E8();
    ~E8();
    //int *E8power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif