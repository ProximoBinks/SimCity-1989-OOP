#include "loadTextures.h"

// tutorial class, inherits from load textures
class Tutorial : public loadTextures {
public:
  Tutorial();
  ~Tutorial();
  void runTutorial();
  int *l = new int;
};