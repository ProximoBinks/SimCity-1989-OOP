#ifndef __GAME_H__
#define __GAME_H__
#include "raylib.h"

//game parent class
class game {
private:
  const int screenWidth = 1280;
  const int screenHeight = 960;

public:
  game();
  int run();
  ~game();
};

#endif