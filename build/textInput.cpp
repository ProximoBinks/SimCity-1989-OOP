#include "textInput.h"
#include <algorithm>
#include <iostream>
using namespace std;
#include "StatusBar.h"
#include "globalVariables.h"
#include "localVariables.h"
#include "squareheaders.h"

// re-define global variables
int intWater;
int intMoney;
int intPopulation;
int intPower;
string stringWater;
string stringMoney;
string stringPopulation;
string stringPower;

// default constructor
textInput::textInput(){};

textInput::~textInput(){};

void textInput::initialise() {
  globalVariables start;
  start.initialise();
}

void textInput::inputText() {

  // Text Box and Input Recognition

  Rectangle textBox = {69, 911, 332, 32};
  if (CheckCollisionPointRec(GetMousePosition(), textBox))
    mouseOnText = true;
  else
    mouseOnText = false;

  if (mouseOnText) {
    SetMouseCursor(MOUSE_CURSOR_IBEAM);

    int key = GetCharPressed();

    while (key > 0) {
      if ((key >= 32) && (key <= 125) && (letterCount < 19)) {
        name[letterCount] = (char)key;
        name[letterCount + 1] = '\0';
        letterCount++;
      }

      key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE) || IsKeyDown(KEY_BACKSPACE)) {
      letterCount--;
      if (letterCount < 0)
        letterCount = 0;
      name[letterCount] = '\0';
    }

  } else
    SetMouseCursor(MOUSE_CURSOR_DEFAULT);

  if (mouseOnText)
    framesCounter++;
  else
    framesCounter = 0;

  DrawText(name, (int)textBox.x, (int)textBox.y + 2, 30, WHITE);

  globalVariables global;
  localVariables local;

  // All the Grid Building Scripts

#pragma region A3
  // checks if enter key is pressed
  if (IsKeyPressed(KEY_ENTER) == true) {

    A3 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    // defines names
    string A3House = "A3 House";
    string A3Clear = "A3 Clear";
    string A3Factory = "A3 Factory";
    string A3Shop = "A3 Shop";
    string A3PowerPlant = "A3 Powerplant";
    string A3WaterPlant = "A3 Waterplant";
    // if statement that checks for if a house is already built
    if ((A3House == name) && (output > houseCost) && (*A3Status != 1)) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      // reassigning variables
      *A3Status = 0;
      *A3Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    // factory version
    if ((A3Factory == name) && (output >= factoryCost) && (*A3Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A3Status = 0;
      *A3Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }
    // shop version
    if ((A3Shop == name) && (output >= shopCost) && (*A3Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A3Status = 0;
      *A3Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    // power plant version
    if ((A3PowerPlant == name) && (output >= powerplantCost) &&
        (*A3Status != 4)) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A3Status = 0;
      *A3Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    // water plant version
    if ((A3WaterPlant == name) && (output >= waterplantCost) &&
        (*A3Status != 5)) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A3Status = 0;
      *A3Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }
    // clears any building on the plot
    if (A3Clear == name) {
      switch (*A3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A3Status = 0;
    }
  }
  // drawing interface
  switch (*A3Status) {
  case 1:
    DrawTexture(residential1, 343, 24, WHITE);
    {
      char A3[24] = "A3 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A3, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 343, 24, WHITE);
    {
      char A3[26] = "A3 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A3, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 343, 20, WHITE);
    {
      char A3[24] = "A3 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A3, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 342, 19, WHITE);
    {
      char A3[29] = "A3 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A3, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 341, 19, WHITE);
    {
      char A3[29] = "A3 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A3, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region A4
  if (IsKeyPressed(KEY_ENTER) == true) {

    A4 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string A4House = "A4 House";
    string A4Clear = "A4 Clear";
    string A4Factory = "A4 Factory";
    string A4Shop = "A4 Shop";
    string A4PowerPlant = "A4 Powerplant";
    string A4WaterPlant = "A4 Waterplant";
    if ((A4House == name) && (output > houseCost) && (*A4Status != 1)) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A4Status = 0;
      *A4Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((A4Factory == name) && (output >= factoryCost) && (*A4Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A4Status = 0;
      *A4Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((A4Shop == name) && (output >= shopCost) && (*A4Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A4Status = 0;
      *A4Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((A4PowerPlant == name) && (output >= powerplantCost) &&
        (*A4Status != 4)) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A4Status = 0;
      *A4Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((A4WaterPlant == name) && (output >= waterplantCost) &&
        (*A4Status != 5)) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A4Status = 0;
      *A4Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (A4Clear == name) {
      switch (*A4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A4Status = 0;
    }
  }

  switch (*A4Status) {
  case 1:
    DrawTexture(residential1, 503, 24, WHITE);
    {
      char A4[24] = "A4 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A4, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 503, 24, WHITE);
    {
      char A4[26] = "A4 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A4, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 503, 20, WHITE);
    {
      char A4[24] = "A4 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A4, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 502, 19, WHITE);
    {
      char A4[29] = "A4 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A4, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 501, 19, WHITE);
    {
      char A4[29] = "A4 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A4, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region A5
  if (IsKeyPressed(KEY_ENTER) == true) {

    A5 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string A5House = "A5 House";
    string A5Clear = "A5 Clear";
    string A5Factory = "A5 Factory";
    string A5Shop = "A5 Shop";
    string A5PowerPlant = "A5 Powerplant";
    string A5WaterPlant = "A5 Waterplant";
    if ((A5House == name) && (output > houseCost) && (*A5Status != 1)) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A5Status = 0;
      *A5Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((A5Factory == name) && (output >= factoryCost) && (*A5Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A5Status = 0;
      *A5Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((A5Shop == name) && (output >= shopCost) && (*A5Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A5Status = 0;
      *A5Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((A5PowerPlant == name) && (output >= powerplantCost) &&
        (*A5Status != 4)) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A5Status = 0;
      *A5Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((A5WaterPlant == name) && (output >= waterplantCost) &&
        (*A5Status != 5)) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A5Status = 0;
      *A5Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (A5Clear == name) {
      switch (*A5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A5Status = 0;
    }
  }

  switch (*A5Status) {
  case 1:
    DrawTexture(residential2, 663, 24, WHITE);
    {
      char A5[24] = "A5 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A5, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 663, 24, WHITE);
    {
      char A5[26] = "A5 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A5, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 663, 24, WHITE);
    {
      char A5[24] = "A5 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A5, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 662, 19, WHITE);
    {
      char A5[29] = "A5 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A5, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 661, 19, WHITE);
    {
      char A5[29] = "A5 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A5, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region A6
  if (IsKeyPressed(KEY_ENTER) == true) {

    A6 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string A6House = "A6 House";
    string A6Clear = "A6 Clear";
    string A6Factory = "A6 Factory";
    string A6Shop = "A6 Shop";
    string A6PowerPlant = "A6 Powerplant";
    string A6WaterPlant = "A6 Waterplant";
    if ((A6House == name) && (output > houseCost) && (*A6Status != 1)) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A6Status = 0;
      *A6Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((A6Factory == name) && (output >= factoryCost) && (*A6Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A6Status = 0;
      *A6Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((A6Shop == name) && (output >= shopCost) && (*A6Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A6Status = 0;
      *A6Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((A6PowerPlant == name) && (output >= powerplantCost) &&
        (*A6Status != 4)) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A6Status = 0;
      *A6Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((A6WaterPlant == name) && (output >= waterplantCost) &&
        (*A6Status != 5)) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A6Status = 0;
      *A6Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (A6Clear == name) {
      switch (*A6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A6Status = 0;
    }
  }

  switch (*A6Status) {
  case 1:
    DrawTexture(residential1, 823, 24, WHITE);
    {
      char A6[24] = "A6 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A6, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 823, 24, WHITE);
    {
      char A6[26] = "A6 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A6, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 823, 20, WHITE);
    {
      char A6[24] = "A6 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A6, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 822, 19, WHITE);
    {
      char A6[29] = "A6 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A6, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 821, 19, WHITE);
    {
      char A6[29] = "A6 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A6, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region A7
  if (IsKeyPressed(KEY_ENTER) == true) {

    A7 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string A7House = "A7 House";
    string A7Clear = "A7 Clear";
    string A7Factory = "A7 Factory";
    string A7Shop = "A7 Shop";
    string A7PowerPlant = "A7 Powerplant";
    string A7WaterPlant = "A7 Waterplant";
    if ((A7House == name) && (output > houseCost) && (*A7Status != 1)) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A7Status = 0;
      *A7Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((A7Factory == name) && (output >= factoryCost) && (*A7Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A7Status = 0;
      *A7Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((A7Shop == name) && (output >= shopCost) && (*A7Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A7Status = 0;
      *A7Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((A7PowerPlant == name) && (output >= powerplantCost) &&
        (*A7Status != 4)) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A7Status = 0;
      *A7Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((A7WaterPlant == name) && (output >= waterplantCost) &&
        (*A7Status != 5)) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A7Status = 0;
      *A7Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (A7Clear == name) {
      switch (*A7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A7Status = 0;
    }
  }

  switch (*A7Status) {
  case 1:
    DrawTexture(residential1, 983, 24, WHITE);
    {
      char A7[24] = "A7 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A7, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 983, 24, WHITE);
    {
      char A7[26] = "A7 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A7, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 983, 24, WHITE);
    {
      char A7[24] = "A7 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A7, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 982, 19, WHITE);
    {
      char A7[29] = "A7 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A7, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 981, 19, WHITE);
    {
      char A7[29] = "A7 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A7, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region A8
  if (IsKeyPressed(KEY_ENTER) == true) {

    A8 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string A8House = "A8 House";
    string A8Clear = "A8 Clear";
    string A8Factory = "A8 Factory";
    string A8Shop = "A8 Shop";
    string A8PowerPlant = "A8 Powerplant";
    string A8WaterPlant = "A8 Waterplant";
    if ((A8House == name) && (output > houseCost) && (*A8Status != 1)) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A8Status = 0;
      *A8Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((A8Factory == name) && (output >= factoryCost) && (*A8Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A8Status = 0;
      *A8Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((A8Shop == name) && (output >= shopCost) && (*A8Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A8Status = 0;
      *A8Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((A8PowerPlant == name) && (output >= powerplantCost) &&
        (*A8Status != 4)) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A8Status = 0;
      *A8Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((A8WaterPlant == name) && (output >= waterplantCost) &&
        (*A8Status != 5)) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *A8Status = 0;
      *A8Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (A8Clear == name) {
      switch (*A8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *A8Status = 0;
    }
  }

  switch (*A8Status) {
  case 1:
    DrawTexture(residential3, 1143, 24, WHITE);
    {
      char A8[24] = "A8 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A8, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 1143, 24, WHITE);
    {
      char A8[26] = "A8 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A8, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 1143, 24, WHITE);
    {
      char A8[24] = "A8 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A8, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 1142, 19, WHITE);
    {
      char A8[29] = "A8 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A8, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 1141, 19, WHITE);
    {
      char A8[29] = "A8 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(A8, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B3
  if (IsKeyPressed(KEY_ENTER) == true) {

    B3 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B3House = "B3 House";
    string B3Clear = "B3 Clear";
    string B3Factory = "B3 Factory";
    string B3Shop = "B3 Shop";
    string B3PowerPlant = "B3 Powerplant";
    string B3WaterPlant = "B3 Waterplant";
    if ((B3House == name) && (output > houseCost) && (*B3Status != 1)) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B3Status = 0;
      *B3Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B3Factory == name) && (output >= factoryCost) && (*B3Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B3Status = 0;
      *B3Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B3Shop == name) && (output >= shopCost) && (*B3Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B3Status = 0;
      *B3Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B3PowerPlant == name) && (output >= powerplantCost) &&
        (*B3Status != 4)) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B3Status = 0;
      *B3Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B3WaterPlant == name) && (output >= waterplantCost) &&
        (*B3Status != 5)) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B3Status = 0;
      *B3Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B3Clear == name) {
      switch (*B3Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B3Status = 0;
    }
  }

  switch (*B3Status) {
  case 1:
    DrawTexture(residential3, 343, 184, WHITE);
    {
      char B3[24] = "B3 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B3, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 343, 184, WHITE);
    {
      char B3[26] = "B3 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B3, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial3, 343, 184, WHITE);
    {
      char B3[24] = "B3 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B3, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 342, 179, WHITE);
    {
      char B3[29] = "B3 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B3, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 341, 179, WHITE);
    {
      char B3[29] = "B3 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B3, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B4
  if (IsKeyPressed(KEY_ENTER) == true) {

    B4 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B4House = "B4 House";
    string B4Clear = "B4 Clear";
    string B4Factory = "B4 Factory";
    string B4Shop = "B4 Shop";
    string B4PowerPlant = "B4 Powerplant";
    string B4WaterPlant = "B4 Waterplant";
    if ((B4House == name) && (output > houseCost) && (*B4Status != 1)) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B4Status = 0;
      *B4Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B4Factory == name) && (output >= factoryCost) && (*B4Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B4Status = 0;
      *B4Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B4Shop == name) && (output >= shopCost) && (*B4Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B4Status = 0;
      *B4Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B4PowerPlant == name) && (output >= powerplantCost) &&
        (*B4Status != 4)) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B4Status = 0;
      *B4Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B4WaterPlant == name) && (output >= waterplantCost) &&
        (*B4Status != 5)) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B4Status = 0;
      *B4Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B4Clear == name) {
      switch (*B4Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B4Status = 0;
    }
  }

  switch (*B4Status) {
  case 1:
    DrawTexture(residential4, 503, 184, WHITE);
    {
      char B4[24] = "B4 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B4, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 503, 184, WHITE);
    {
      char B4[26] = "B4 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B4, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 503, 184, WHITE);
    {
      char B4[24] = "B4 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B4, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 502, 179, WHITE);
    {
      char B4[29] = "B4 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B4, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 501, 179, WHITE);
    {
      char B4[29] = "B4 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B4, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B5
  if (IsKeyPressed(KEY_ENTER) == true) {

    B5 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B5House = "B5 House";
    string B5Clear = "B5 Clear";
    string B5Factory = "B5 Factory";
    string B5Shop = "B5 Shop";
    string B5PowerPlant = "B5 Powerplant";
    string B5WaterPlant = "B5 Waterplant";
    if ((B5House == name) && (output > houseCost) && (*B5Status != 1)) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B5Status = 0;
      *B5Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B5Factory == name) && (output >= factoryCost) && (*B5Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B5Status = 0;
      *B5Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B5Shop == name) && (output >= shopCost) && (*B5Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B5Status = 0;
      *B5Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B5PowerPlant == name) && (output >= powerplantCost) &&
        (*B5Status != 4)) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B5Status = 0;
      *B5Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B5WaterPlant == name) && (output >= waterplantCost) &&
        (*B5Status != 5)) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B5Status = 0;
      *B5Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B5Clear == name) {
      switch (*B5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B5Status = 0;
    }
  }

  switch (*B5Status) {
  case 1:
    DrawTexture(residential2, 663, 184, WHITE);
    {
      char B5[24] = "B5 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B5, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 663, 184, WHITE);
    {
      char B5[26] = "B5 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B5, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 663, 184, WHITE);
    {
      char B5[24] = "B5 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B5, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 662, 179, WHITE);
    {
      char B5[29] = "B5 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B5, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 661, 179, WHITE);
    {
      char B5[29] = "B5 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B5, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B6
  if (IsKeyPressed(KEY_ENTER) == true) {

    B6 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B6House = "B6 House";
    string B6Clear = "B6 Clear";
    string B6Factory = "B6 Factory";
    string B6Shop = "B6 Shop";
    string B6PowerPlant = "B6 Powerplant";
    string B6WaterPlant = "B6 Waterplant";
    if ((B6House == name) && (output > houseCost) && (*B6Status != 1)) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B6Status = 0;
      *B6Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B6Factory == name) && (output >= factoryCost) && (*B6Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B6Status = 0;
      *B6Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B6Shop == name) && (output >= shopCost) && (*B6Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B6Status = 0;
      *B6Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B6PowerPlant == name) && (output >= powerplantCost) &&
        (*B6Status != 4)) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B6Status = 0;
      *B6Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B6WaterPlant == name) && (output >= waterplantCost) &&
        (*B6Status != 5)) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B6Status = 0;
      *B6Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B6Clear == name) {
      switch (*B6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B6Status = 0;
    }
  }

  switch (*B6Status) {
  case 1:
    DrawTexture(residential4, 823, 184, WHITE);
    {
      char B6[24] = "B6 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B6, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 823, 184, WHITE);
    {
      char B6[26] = "B6 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B6, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 823, 184, WHITE);
    {
      char B6[24] = "B6 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B6, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 822, 179, WHITE);
    {
      char B6[29] = "B6 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B6, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 821, 179, WHITE);
    {
      char B6[29] = "B6 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B6, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B7
  if (IsKeyPressed(KEY_ENTER) == true) {

    B7 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B7House = "B7 House";
    string B7Clear = "B7 Clear";
    string B7Factory = "B7 Factory";
    string B7Shop = "B7 Shop";
    string B7PowerPlant = "B7 Powerplant";
    string B7WaterPlant = "B7 Waterplant";
    if ((B7House == name) && (output > houseCost) && (*B7Status != 1)) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B7Status = 0;
      *B7Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B7Factory == name) && (output >= factoryCost) && (*B7Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B7Status = 0;
      *B7Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B7Shop == name) && (output >= shopCost) && (*B7Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B7Status = 0;
      *B7Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B7PowerPlant == name) && (output >= powerplantCost) &&
        (*B7Status != 4)) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B7Status = 0;
      *B7Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B7WaterPlant == name) && (output >= waterplantCost) &&
        (*B7Status != 5)) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B7Status = 0;
      *B7Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B7Clear == name) {
      switch (*B7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B7Status = 0;
    }
  }

  switch (*B7Status) {
  case 1:
    DrawTexture(residential2, 983, 184, WHITE);
    {
      char B7[24] = "B7 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B7, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 983, 184, WHITE);
    {
      char B7[26] = "B7 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B7, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial3, 983, 184, WHITE);
    {
      char B7[24] = "B7 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B7, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 982, 179, WHITE);
    {
      char B7[29] = "B7 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B7, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 981, 179, WHITE);
    {
      char B7[29] = "B7 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B7, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region B8
  if (IsKeyPressed(KEY_ENTER) == true) {

    B8 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string B8House = "B8 House";
    string B8Clear = "B8 Clear";
    string B8Factory = "B8 Factory";
    string B8Shop = "B8 Shop";
    string B8PowerPlant = "B8 Powerplant";
    string B8WaterPlant = "B8 Waterplant";
    if ((B8House == name) && (output > houseCost) && (*B8Status != 1)) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B8Status = 0;
      *B8Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((B8Factory == name) && (output >= factoryCost) && (*B8Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B8Status = 0;
      *B8Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((B8Shop == name) && (output >= shopCost) && (*B8Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B8Status = 0;
      *B8Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((B8PowerPlant == name) && (output >= powerplantCost) &&
        (*B8Status != 4)) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B8Status = 0;
      *B8Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((B8WaterPlant == name) && (output >= waterplantCost) &&
        (*B8Status != 5)) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *B8Status = 0;
      *B8Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (B8Clear == name) {
      switch (*B8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *B8Status = 0;
    }
  }

  switch (*B8Status) {
  case 1:
    DrawTexture(residential1, 1143, 184, WHITE);
    {
      char B8[24] = "B8 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B8, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 1143, 184, WHITE);
    {
      char B8[26] = "B8 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B8, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 1143, 184, WHITE);
    {
      char B8[24] = "B8 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B8, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 1142, 179, WHITE);
    {
      char B8[29] = "B8 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B8, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 1141, 179, WHITE);
    {
      char B8[29] = "B8 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(B8, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region C5
  if (IsKeyPressed(KEY_ENTER) == true) {

    C5 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string C5House = "C5 House";
    string C5Clear = "C5 Clear";
    string C5Factory = "C5 Factory";
    string C5Shop = "C5 Shop";
    string C5PowerPlant = "C5 Powerplant";
    string C5WaterPlant = "C5 Waterplant";
    if ((C5House == name) && (output > houseCost) && (*C5Status != 1)) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C5Status = 0;
      *C5Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((C5Factory == name) && (output >= factoryCost) && (*C5Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C5Status = 0;
      *C5Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((C5Shop == name) && (output >= shopCost) && (*C5Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C5Status = 0;
      *C5Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((C5PowerPlant == name) && (output >= powerplantCost) &&
        (*C5Status != 4)) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C5Status = 0;
      *C5Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((C5WaterPlant == name) && (output >= waterplantCost) &&
        (*C5Status != 5)) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C5Status = 0;
      *C5Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (C5Clear == name) {
      switch (*C5Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *C5Status = 0;
    }
  }

  switch (*C5Status) {
  case 1:
    DrawTexture(residential3, 663, 344, WHITE);
    {
      char C5[24] = "C5 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C5, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 663, 344, WHITE);
    {
      char C5[26] = "C5 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C5, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial3, 663, 344, WHITE);
    {
      char C5[24] = "C5 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C5, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 662, 349, WHITE);
    {
      char C5[29] = "C5 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C5, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 661, 349, WHITE);
    {
      char C5[29] = "C5 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C5, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region C6
  if (IsKeyPressed(KEY_ENTER) == true) {

    C6 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string C6House = "C6 House";
    string C6Clear = "C6 Clear";
    string C6Factory = "C6 Factory";
    string C6Shop = "C6 Shop";
    string C6PowerPlant = "C6 Powerplant";
    string C6WaterPlant = "C6 Waterplant";
    if ((C6House == name) && (output > houseCost) && (*C6Status != 1)) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C6Status = 0;
      *C6Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((C6Factory == name) && (output >= factoryCost) && (*C6Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C6Status = 0;
      *C6Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((C6Shop == name) && (output >= shopCost) && (*C6Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C6Status = 0;
      *C6Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((C6PowerPlant == name) && (output >= powerplantCost) &&
        (*C6Status != 4)) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C6Status = 0;
      *C6Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((C6WaterPlant == name) && (output >= waterplantCost) &&
        (*C6Status != 5)) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C6Status = 0;
      *C6Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (C6Clear == name) {
      switch (*C6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *C6Status = 0;
    }
  }

  switch (*C6Status) {
  case 1:
    DrawTexture(residential4, 823, 344, WHITE);
    {
      char C6[24] = "C6 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C6, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 823, 344, WHITE);
    {
      char C6[26] = "C6 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C6, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 823, 344, WHITE);
    {
      char C6[24] = "C6 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C6, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 822, 349, WHITE);
    {
      char C6[29] = "C6 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C6, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 821, 349, WHITE);
    {
      char C6[29] = "C6 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C6, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region C7
  if (IsKeyPressed(KEY_ENTER) == true) {

    C7 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string C7House = "C7 House";
    string C7Clear = "C7 Clear";
    string C7Factory = "C7 Factory";
    string C7Shop = "C7 Shop";
    string C7PowerPlant = "C7 Powerplant";
    string C7WaterPlant = "C7 Waterplant";
    if ((C7House == name) && (output > houseCost) && (*C7Status != 1)) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C7Status = 0;
      *C7Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((C7Factory == name) && (output >= factoryCost) && (*C7Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C7Status = 0;
      *C7Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((C7Shop == name) && (output >= shopCost) && (*C7Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C7Status = 0;
      *C7Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((C7PowerPlant == name) && (output >= powerplantCost) &&
        (*C7Status != 4)) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C7Status = 0;
      *C7Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((C7WaterPlant == name) && (output >= waterplantCost) &&
        (*C7Status != 5)) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C7Status = 0;
      *C7Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (C7Clear == name) {
      switch (*C7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *C7Status = 0;
    }
  }

  switch (*C7Status) {
  case 1:
    DrawTexture(residential2, 983, 344, WHITE);
    {
      char C7[24] = "C7 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C7, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 983, 344, WHITE);
    {
      char C7[26] = "C7 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C7, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 983, 344, WHITE);
    {
      char C7[24] = "C7 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C7, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 982, 349, WHITE);
    {
      char C7[29] = "C7 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C7, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 981, 349, WHITE);
    {
      char C7[29] = "C7 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C7, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region C8
  if (IsKeyPressed(KEY_ENTER) == true) {

    C8 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string C8House = "C8 House";
    string C8Clear = "C8 Clear";
    string C8Factory = "C8 Factory";
    string C8Shop = "C8 Shop";
    string C8PowerPlant = "C8 Powerplant";
    string C8WaterPlant = "C8 Waterplant";
    if ((C8House == name) && (output > houseCost) && (*C8Status != 1)) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C8Status = 0;
      *C8Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((C8Factory == name) && (output >= factoryCost) && (*C8Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C8Status = 0;
      *C8Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((C8Shop == name) && (output >= shopCost) && (*C8Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C8Status = 0;
      *C8Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((C8PowerPlant == name) && (output >= powerplantCost) &&
        (*C8Status != 4)) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C8Status = 0;
      *C8Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((C8WaterPlant == name) && (output >= waterplantCost) &&
        (*C8Status != 5)) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *C8Status = 0;
      *C8Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (C8Clear == name) {
      switch (*C8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *C8Status = 0;
    }
  }

  switch (*C8Status) {
  case 1:
    DrawTexture(residential4, 1143, 344, WHITE);
    {
      char C8[24] = "C8 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C8, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 1143, 344, WHITE);
    {
      char C8[26] = "C8 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C8, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 1143, 344, WHITE);
    {
      char C8[24] = "C8 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C8, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 1142, 349, WHITE);
    {
      char C8[29] = "C8 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C8, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 1141, 349, WHITE);
    {
      char C8[29] = "C8 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(C8, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region D6
  if (IsKeyPressed(KEY_ENTER) == true) {

    D6 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string D6House = "D6 House";
    string D6Clear = "D6 Clear";
    string D6Factory = "D6 Factory";
    string D6Shop = "D6 Shop";
    string D6PowerPlant = "D6 Powerplant";
    string D6WaterPlant = "D6 Waterplant";
    if ((D6House == name) && (output > houseCost) && (*D6Status != 1)) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D6Status = 0;
      *D6Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((D6Factory == name) && (output >= factoryCost) && (*D6Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D6Status = 0;
      *D6Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((D6Shop == name) && (output >= shopCost) && (*D6Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D6Status = 0;
      *D6Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((D6PowerPlant == name) && (output >= powerplantCost) &&
        (*D6Status != 4)) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D6Status = 0;
      *D6Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((D6WaterPlant == name) && (output >= waterplantCost) &&
        (*D6Status != 5)) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D6Status = 0;
      *D6Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (D6Clear == name) {
      switch (*D6Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *D6Status = 0;
    }
  }

  switch (*D6Status) {
  case 1:
    DrawTexture(residential4, 823, 504, WHITE);
    {
      char D6[24] = "D6 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D6, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 823, 504, WHITE);
    {
      char D6[26] = "D6 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D6, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 823, 504, WHITE);
    {
      char D6[24] = "D6 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D6, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 822, 509, WHITE);
    {
      char D6[29] = "D6 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D6, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 821, 509, WHITE);
    {
      char D6[29] = "D6 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D6, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region D7
  if (IsKeyPressed(KEY_ENTER) == true) {

    D7 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string D7House = "D7 House";
    string D7Clear = "D7 Clear";
    string D7Factory = "D7 Factory";
    string D7Shop = "D7 Shop";
    string D7PowerPlant = "D7 Powerplant";
    string D7WaterPlant = "D7 Waterplant";
    if ((D7House == name) && (output > houseCost) && (*D7Status != 1)) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D7Status = 0;
      *D7Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((D7Factory == name) && (output >= factoryCost) && (*D7Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D7Status = 0;
      *D7Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((D7Shop == name) && (output >= shopCost) && (*D7Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D7Status = 0;
      *D7Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((D7PowerPlant == name) && (output >= powerplantCost) &&
        (*D7Status != 4)) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D7Status = 0;
      *D7Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((D7WaterPlant == name) && (output >= waterplantCost) &&
        (*D7Status != 5)) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D7Status = 0;
      *D7Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (D7Clear == name) {
      switch (*D7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *D7Status = 0;
    }
  }

  switch (*D7Status) {
  case 1:
    DrawTexture(residential2, 983, 504, WHITE);
    {
      char D7[24] = "D7 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D7, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 983, 504, WHITE);
    {
      char D7[26] = "D7 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D7, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 983, 504, WHITE);
    {
      char D7[24] = "D7 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D7, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 982, 509, WHITE);
    {
      char D7[29] = "D7 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D7, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 981, 509, WHITE);
    {
      char D7[29] = "D7 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D7, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region D8
  if (IsKeyPressed(KEY_ENTER) == true) {

    D8 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string D8House = "D8 House";
    string D8Clear = "D8 Clear";
    string D8Factory = "D8 Factory";
    string D8Shop = "D8 Shop";
    string D8PowerPlant = "D8 Powerplant";
    string D8WaterPlant = "D8 Waterplant";
    if ((D8House == name) && (output > houseCost) && (*D8Status != 1)) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D8Status = 0;
      *D8Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((D8Factory == name) && (output >= factoryCost) && (*D8Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D8Status = 0;
      *D8Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((D8Shop == name) && (output >= shopCost) && (*D8Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D8Status = 0;
      *D8Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((D8PowerPlant == name) && (output >= powerplantCost) &&
        (*D8Status != 4)) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D8Status = 0;
      *D8Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((D8WaterPlant == name) && (output >= waterplantCost) &&
        (*D8Status != 5)) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *D8Status = 0;
      *D8Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (D8Clear == name) {
      switch (*D8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *D8Status = 0;
    }
  }

  switch (*D8Status) {
  case 1:
    DrawTexture(residential4, 1143, 504, WHITE);
    {
      char D8[24] = "D8 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D8, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 1143, 504, WHITE);
    {
      char D8[26] = "D8 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D8, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial1, 1143, 504, WHITE);
    {
      char D8[24] = "D8 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D8, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 1142, 509, WHITE);
    {
      char D8[29] = "D8 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D8, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 1141, 509, WHITE);
    {
      char D8[29] = "D8 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(D8, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region E1
  if (IsKeyPressed(KEY_ENTER) == true) {

    E1 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string E1House = "E1 House";
    string E1Clear = "E1 Clear";
    string E1Factory = "E1 Factory";
    string E1Shop = "E1 Shop";
    string E1PowerPlant = "E1 Powerplant";
    string E1WaterPlant = "E1 Waterplant";
    if ((E1House == name) && (output > houseCost) && (*E1Status != 1)) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E1Status = 0;
      *E1Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((E1Factory == name) && (output >= factoryCost) && (*E1Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E1Status = 0;
      *E1Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((E1Shop == name) && (output >= shopCost) && (*E1Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E1Status = 0;
      *E1Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((E1PowerPlant == name) && (output >= powerplantCost) &&
        (*E1Status != 4)) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E1Status = 0;
      *E1Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((E1WaterPlant == name) && (output >= waterplantCost) &&
        (*E1Status != 5)) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E1Status = 0;
      *E1Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (E1Clear == name) {
      switch (*E1Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *E1Status = 0;
    }
  }

  switch (*E1Status) {
  case 1:
    DrawTexture(residential1, 24, 664, WHITE);
    {
      char E1[24] = "E1 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E1, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 24, 664, WHITE);
    {
      char E1[26] = "E1 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E1, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 24, 664, WHITE);
    {
      char E1[24] = "E1 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E1, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 23, 669, WHITE);
    {
      char E1[29] = "E1 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E1, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 22, 669, WHITE);
    {
      char E1[29] = "E1 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E1, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region E2
  if (IsKeyPressed(KEY_ENTER) == true) {

    E2 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string E2House = "E2 House";
    string E2Clear = "E2 Clear";
    string E2Factory = "E2 Factory";
    string E2Shop = "E2 Shop";
    string E2PowerPlant = "E2 Powerplant";
    string E2WaterPlant = "E2 Waterplant";
    if ((E2House == name) && (output > houseCost) && (*E2Status != 1)) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E2Status = 0;
      *E2Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((E2Factory == name) && (output >= factoryCost) && (*E2Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E2Status = 0;
      *E2Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((E2Shop == name) && (output >= shopCost) && (*E2Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E2Status = 0;
      *E2Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((E2PowerPlant == name) && (output >= powerplantCost) &&
        (*E2Status != 4)) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E2Status = 0;
      *E2Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((E2WaterPlant == name) && (output >= waterplantCost) &&
        (*E2Status != 5)) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E2Status = 0;
      *E2Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (E2Clear == name) {
      switch (*E2Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *E2Status = 0;
    }
  }

  switch (*E2Status) {
  case 1:
    DrawTexture(residential1, 184, 664, WHITE);
    {
      char E2[24] = "E2 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E2, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial2, 184, 664, WHITE);
    {
      char E2[26] = "E2 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E2, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 184, 664, WHITE);
    {
      char E2[24] = "E2 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E2, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 183, 669, WHITE);
    {
      char E2[29] = "E2 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E2, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 181, 669, WHITE);
    {
      char E2[29] = "E2 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E2, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region E8
  if (IsKeyPressed(KEY_ENTER) == true) {

    E8 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string E8House = "E8 House";
    string E8Clear = "E8 Clear";
    string E8Factory = "E8 Factory";
    string E8Shop = "E8 Shop";
    string E8PowerPlant = "E8 Powerplant";
    string E8WaterPlant = "E8 Waterplant";
    if ((E8House == name) && (output > houseCost) && (*E8Status != 1)) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E8Status = 0;
      *E8Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((E8Factory == name) && (output >= factoryCost) && (*E8Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E8Status = 0;
      *E8Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((E8Shop == name) && (output >= shopCost) && (*E8Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E8Status = 0;
      *E8Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((E8PowerPlant == name) && (output >= powerplantCost) &&
        (*E8Status != 4)) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E8Status = 0;
      *E8Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((E8WaterPlant == name) && (output >= waterplantCost) &&
        (*E8Status != 5)) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E8Status = 0;
      *E8Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (E8Clear == name) {
      switch (*E8Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *E8Status = 0;
    }
  }

  switch (*E8Status) {
  case 1:
    DrawTexture(residential2, 1143, 664, WHITE);
    {
      char E8[24] = "E8 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E8, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 1143, 664, WHITE);
    {
      char E8[26] = "E8 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E8, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial3, 1143, 664, WHITE);
    {
      char E8[24] = "E8 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E8, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 1142, 669, WHITE);
    {
      char E8[29] = "E8 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E8, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 1141, 669, WHITE);
    {
      char E8[29] = "E8 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E8, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

#pragma region E7
  if (IsKeyPressed(KEY_ENTER) == true) {

    E7 square;
    local.initialise();
    global.population();
    global.power();
    global.water();
    string E7House = "E7 House";
    string E7Clear = "E7 Clear";
    string E7Factory = "E7 Factory";
    string E7Shop = "E7 Shop";
    string E7PowerPlant = "E7 Powerplant";
    string E7WaterPlant = "E7 Waterplant";
    if ((E7House == name) && (output > houseCost) && (*E7Status != 1)) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E7Status = 0;
      *E7Status = 1;
      square.house();
      global.water();
      global.power();
      global.population();
      noHouse++;
    }
    if ((E7Factory == name) && (output >= factoryCost) && (*E7Status != 2) &&
        (global.water() >= (-1 * factoryWater)) &&
        (global.water() >= (-1 * factoryWater))) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E7Status = 0;
      *E7Status = 2;
      square.factory();
      global.water();
      global.power();
      global.population();
      noFactory++;
    }

    if ((E7Shop == name) && (output >= shopCost) && (*E7Status != 3) &&
        (global.population() >= 5) && (noFactory > noShop)) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E7Status = 0;
      *E7Status = 3;
      square.shop();
      global.water();
      global.power();
      global.population();
      noShop++;
    }
    if ((E7PowerPlant == name) && (output >= powerplantCost) &&
        (*E7Status != 4)) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E7Status = 0;
      *E7Status = 4;
      square.powerplant();
      global.water();
      global.power();
      global.population();
      noPowerplant++;
    }
    if ((E7WaterPlant == name) && (output >= waterplantCost) &&
        (*E7Status != 5)) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      }
      *E7Status = 0;
      *E7Status = 5;
      square.waterplant();
      global.water();
      global.power();
      global.population();
      noWaterplant++;
    }

    if (E7Clear == name) {
      switch (*E7Status) {
      case 1:
        noHouse--;
        cout << "You have " << noHouse << " house(s) left" << endl;
        break;
      case 2:
        noFactory--;
        cout << "You have " << noFactory << " factory(s) left" << endl;
        break;
      case 3:
        noShop--;
        cout << "You have " << noShop << " shop(s) left" << endl;
        break;
      case 4:
        noPowerplant--;
        cout << "You have " << noPowerplant << " power plant(s) left" << endl;
        break;
      case 5:
        noWaterplant--;
        cout << "You have " << noWaterplant << " water plant(s) left" << endl;
        break;
      case 0:
        cout << "This space is empty!" << endl;
      }
      square.clear();
      *E7Status = 0;
    }
  }

  switch (*E7Status) {
  case 1:
    DrawTexture(residential2, 983, 664, WHITE);
    {
      char E7[24] = "E7 House Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E7, 100, 830, 40, WHITE);
    }
    break;

  case 2:
    DrawTexture(industrial1, 983, 664, WHITE);
    {
      char E7[26] = "E7 Factory Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E7, 100, 830, 40, WHITE);
    }
    break;

  case 3:
    DrawTexture(commercial2, 983, 664, WHITE);
    {
      char E7[24] = "E7 Shop Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E7, 100, 830, 40, WHITE);
    }
    break;

  case 4:
    DrawTexture(powerplant, 982, 669, WHITE);
    {
      char E7[29] = "E7 Powerplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E7, 100, 830, 40, WHITE);
    }
    break;

  case 5:
    DrawTexture(waterplant, 981, 669, WHITE);
    {
      char E7[29] = "E7 Waterplant Has Been Built";
      DrawTexture(feedback, 0, 0, WHITE);
      DrawText(E7, 100, 830, 40, WHITE);
    }
    break;
  }
#pragma endregion

  // Delete Key

  if (IsKeyPressed(KEY_ENTER)) {
    for (letterCount = letterCount; letterCount >= 0; letterCount--) {
      name[letterCount] = '\0';
    }
  }

  // Status Bar displaying Power, Water, Money and Population

  StatusBar power, water, money, population;
  power.runStatusBarPower(global.power());
  water.runStatusBarWater(global.water());
  money.runStatusBarMoney(output);
  population.runStatusBarPopulation(global.population());
  DrawTexture(gridOverlay, 0, 0, RAYWHITE);

}