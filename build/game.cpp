#include "game.h"
#include "LoadMenu.h"
#include "StatusBar.h"
#include "Tutorial.h"
#include "globalVariables.h"
#include "iostream"
#include "loadTextures.h"
#include "raylib.h"
#include "textInput.h"

using namespace std;
// default constructor
game::game(){};

// object run
int game::run() {
  // set window dimensions
  const int screenWidth = 1280;
  const int screenHeight = 960;
  InitWindow(screenWidth, screenHeight, "SimCity");
  // set target fps
  SetTargetFPS(10);
  // load textures and pictures
  loadTextures pictures;
  textInput chatbox;
  LoadMenu menu;
  // load classes in
  globalVariables n;
  Tutorial tutorial;
  chatbox.initialise();
  menu.initialiseScreen();
  StatusBar time;
  time.initialise();

  // Window close key
  while (!WindowShouldClose()) // Detect window close button or ESC key
  {
    BeginDrawing();

    pictures.run2();
    tutorial.runTutorial();
    chatbox.inputText();
    time.runTime();
    menu.runMenu();
    EndDrawing();
  }
  globalVariables stats;
  CloseWindow();
  cout << "Your final balance was: $" << output << endl;
  cout << "Your final population was: " << stats.population() << " people" << endl;
  return 0;
};

game::~game(){};