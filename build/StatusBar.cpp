#include "StatusBar.h"
#include "globalVariables.h"
#include "iostream"
#include "math.h"
#include "raylib.h"
#include "textInput.h"

using namespace std;
// default constructor
StatusBar::StatusBar(){};
StatusBar::~StatusBar(){};

// status bar initialisation
void StatusBar::runStatusBarMoney(int n) {
  stringMoney = std::to_string(n);
  char const *charMoney = stringMoney.c_str();
  DrawText(charMoney, 1028, 913, 30, WHITE);
}

void StatusBar::runStatusBarPower(int n) {
  stringPower = std::to_string(n);
  char const *charPower = stringPower.c_str();
  DrawText(charPower, 514, 913, 30, WHITE);
}

void StatusBar::runStatusBarWater(int n) {
  stringWater = std::to_string(n);
  char const *charWater = stringWater.c_str();
  DrawText(charWater, 655, 913, 30, WHITE);
}

void StatusBar::runStatusBarPopulation(int n) {
  stringPopulation = std::to_string(n);
  char const *charPopulation = stringPopulation.c_str();
  DrawText(charPopulation, 805, 913, 30, WHITE);
}

void StatusBar::initialise() { day = 0; }

// initialise timer
void StatusBar::runTime() {
  int time = GetTime();
  int i = 1;
  if ((time % 30 * i) == 0) {
    day = day + 1;
    i++;
    output = output + (((noShop * 300) + (noFactory * 200)) / 5) + 500 / 5;
    globalPower = globalPower -
                  (((noShop * 50) + (noFactory * 60) + (noHouse * 20)) / 5) +
                  20 * noPowerplant;
    globalWater = globalWater -
                  (((noShop * 50) + (noFactory * 60) + (noHouse * 20)) / 5) +
                  20 * noWaterplant;
  }
  string stringDays = std::to_string(day);
  char const *charDays = stringDays.c_str();
  DrawText(charDays, 35, 90, 70, BLACK);

  // closes game at day 500 and displays the stats in the terminal
  globalVariables stats;
  if (day == 500) {
    CloseWindow();
    cout << "Your final money was: $" << output << endl;
    cout << "Your final population was: " << stats.population() << endl;
  }
}

int StatusBar::getDay() { return day; }