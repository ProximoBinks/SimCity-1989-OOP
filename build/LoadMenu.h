#include "loadTextures.h"

class LoadMenu : public loadTextures {
public:
  LoadMenu();
  ~LoadMenu();
  void runMenu();
  int currentScreen;
  void initialiseScreen();
};