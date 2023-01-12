#include <SDL2/SDL.h>
#include <math.h>
#include "../../objects/shapes/hexagon.cpp"

class Portal {
public:
  Portal();
  ~Portal();
  void draw(SDL_Renderer *renderer);
  pos getPosition();

private:
  Hexagon *hexagon;
};