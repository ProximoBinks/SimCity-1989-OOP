#ifndef __LOADTEXTURES_H__
#define __LOADTEXTURES_H__

#include "game.h"

// load textures class that inherits from game
class loadTextures : public game {
public:
  Texture2D map = LoadTexture("map1.png");
  Texture2D residential1 = LoadTexture("residential1.png");
  Texture2D residential2 = LoadTexture("residential2.png");
  Texture2D residential3 = LoadTexture("residential3.png");
  Texture2D residential4 = LoadTexture("residential4.png");
  Texture2D residential5 = LoadTexture("residential5.png");
  Texture2D commercial1 = LoadTexture("commercial1.png");
  Texture2D commercial2 = LoadTexture("commercial2.png");
  Texture2D commercial3 = LoadTexture("commercial3.png");
  Texture2D industrial1 = LoadTexture("industrial1.png");
  Texture2D industrial2 = LoadTexture("industrial2.png");
  Texture2D powerplant = LoadTexture("powerplant.png");
  Texture2D waterplant = LoadTexture("waterplant.png");
  Texture2D statusbar = LoadTexture("status.png");
  Texture2D qmark = LoadTexture("qmark.png");
  Texture2D tutorial = LoadTexture("Tutorial.png");
  Texture2D gridOverlay = LoadTexture("gridtransparent.png");
  Texture2D menu = LoadTexture("loadmenu.png");
  Rectangle textBox = {69, 911, 332, 32};
  Rectangle qmarkBox = {4, 839, 48, 48};
  Rectangle tutorialBox = {256, 302, 272, 91};
  Texture2D feedback = LoadTexture("feedbackBox.png");
  Texture2D calender = LoadTexture("calender.png");
  Image icon = LoadImage("simcity.png");
  loadTextures();
  void run1();
  void run2();
  ~loadTextures();
};

#endif