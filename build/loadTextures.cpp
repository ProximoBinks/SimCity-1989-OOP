#include "loadTextures.h"

// default constructor
loadTextures::loadTextures(){};

// run2 object
void loadTextures::run2() {

  ClearBackground(RAYWHITE);
  DrawTexture(map, 0, 0, RAYWHITE);
  DrawTexture(statusbar, 0, 0, RAYWHITE);
  DrawTexture(qmark, 0, 833, RAYWHITE);
  DrawRectangleRec(textBox, BLANK);
  DrawTexture(calender, 0, 0, RAYWHITE);
}

loadTextures::~loadTextures(){};