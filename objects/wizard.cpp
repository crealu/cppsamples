#include <iostream>
#include <SDL2/SDL.h>
#include "shapes/triangle.cpp"

class Wizard {
public:
  Wizard(SDL_Color wizardColor);
  ~Wizard();
  void draw(SDL_Renderer *renderer);
  void move(bool near);
  position getPosition();

protected:
  FilledTriangle *wizardHat;
  SDL_Rect pRect;
  SDL_Color color;
  int speed;
};

Wizard::Wizard(SDL_Color wizardColor) {
  SDL_Rect rect = {400, 150, 30, 30};
  pRect = rect;
  wizardHat = new FilledTriangle(wizardColor, 100, 170);
  color = wizardColor;
  speed = 2;
}

Wizard::~Wizard() {}

void Wizard::draw(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);
  SDL_RenderFillRect(renderer, &pRect);
  wizardHat->draw(renderer);
}

void Wizard::move(bool near) {
  if (!near) {
    pRect.x -= speed;
    if (pRect.x <= 300)
      speed = -speed;
    if (pRect.x >= 500)
      speed = -speed;
  }
}

position Wizard::getPosition() {
  position pos = {pRect.x, pRect.y};
  return pos;
}
