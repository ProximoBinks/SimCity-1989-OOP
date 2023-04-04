#ifndef __E2_H__
#define __E2_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int E2population;
extern int E2water;
extern int E2power;
extern int E2money;

class E2{
    public:
    E2();
    ~E2();
    //int *E2power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif