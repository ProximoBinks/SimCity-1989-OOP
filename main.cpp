#include "build/game.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Game Starting..." << endl;
  game instance;
  instance.run();
  cout << "Game has finished." << endl;
  return 0;
}