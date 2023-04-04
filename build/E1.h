#ifndef __E1_H__
#define __E1_H__
#include <string>
#include "raylib.h"
using namespace std;

extern int E1population;
extern int E1water;
extern int E1power;
extern int E1money;

class E1{
    public:
    E1();
    ~E1();
    //int *E1power= new int;
    void house();
    void shop();
    void factory();
    void powerplant();
    void waterplant();
    void clear();
};

#endif