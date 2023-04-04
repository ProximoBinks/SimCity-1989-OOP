#include "globalVariables.h"
#include "textInput.h"

// class status bar
class StatusBar {
public:
  StatusBar();
  ~StatusBar();
  // status bar objects
  void runStatusBarWater(int n);
  void runStatusBarMoney(int n);
  void runStatusBarPower(int n);
  void runStatusBarPopulation(int n);
  void runTime();
  int day;
  void initialise();
  int getDay();
};