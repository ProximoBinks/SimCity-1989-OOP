#include "Tutorial.h"

// default constructor
Tutorial::Tutorial(){};
Tutorial::~Tutorial(){};

// tutorial class
void Tutorial::runTutorial() {

  if (CheckCollisionPointRec(GetMousePosition(), qmarkBox) &&
      IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true) {
    *l = 1;
  }

  if (CheckCollisionPointRec(GetMousePosition(), tutorialBox) &&
      IsMouseButtonPressed(MOUSE_LEFT_BUTTON) == true) {
    *l = 0;
  }

  if (*l == 1) {
    DrawTexture(tutorial, 0, 0, WHITE);
  }
}