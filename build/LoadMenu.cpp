#include "LoadMenu.h"
#include "textInput.h"
using namespace std;

// default constructor
LoadMenu::LoadMenu(){};
LoadMenu::~LoadMenu(){};

// initialise keyboard and mouse to work with interface
void LoadMenu::initialiseScreen() { currentScreen = 1; }

void LoadMenu::runMenu() {

  int x = GetMouseX();
  int y = GetMouseY();

  Rectangle startButton = {443, 480, 377, 82};
  if (((x > 443 && y > 480) && (x < 820 && y < 561)) &&
      (IsMouseButtonDown(MOUSE_BUTTON_LEFT) == true)) {
    currentScreen = 0;
  }

  if (currentScreen == 1) {
    DrawTexture(menu, 0, 0, WHITE);
    DrawRectangle(443, 480, 377, 82, ORANGE);
    DrawRectangleLinesEx(startButton, 10, GOLD);
    char const *playgame = "Play Game";
    DrawText(playgame, 505, 495, 50, WHITE);
  } else {
  }
};