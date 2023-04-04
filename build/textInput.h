#ifndef __TEXTINPUT_H__
#define __TEXTINPUT_H__
#include "globalVariables.h"
#include "loadTextures.h"
#include "raylib.h"
#include <string>

using namespace std;

// class textInput
class textInput : public loadTextures, public globalVariables {
public:
  textInput();
  ~textInput();
  void inputText();
  void initialise();
  // variables check for the type of building
  int *A3Status = new int;
  int *A4Status = new int;
  int *A5Status = new int;
  int *A6Status = new int;
  int *A7Status = new int;
  int *A8Status = new int;
  int *B3Status = new int;
  int *B4Status = new int;
  int *B5Status = new int;
  int *B6Status = new int;
  int *B7Status = new int;
  int *B8Status = new int;
  int *C5Status = new int;
  int *C6Status = new int;
  int *C7Status = new int;
  int *C8Status = new int;
  int *D6Status = new int;
  int *D7Status = new int;
  int *D8Status = new int;
  int *E1Status = new int;
  int *E2Status = new int;
  int *E7Status = new int;
  int *E8Status = new int;
  int framesCounter = 0;
  bool mouseOnText = false;
  int letterCount = 0;
  char name[19] = "\0";
};

#endif