#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "main.hpp"
#include "entity.cpp"
using namespace std;

#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480

void drawBackground(SDL_Renderer *renderer);
int quitGame(int running, SDL_Window *window, SDL_Event &event);
void checkVicinity(Player player, Wizard wizard, SDL_Event &event);

int main(int arc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Event event;

  window = SDL_CreateWindow("Game Window",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    0
  );

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  TTF_Init();
  TTF_Font *theFont = TTF_OpenFont("Comfortaa[wght].ttf", 24);

  if (!theFont) {
    printf("TTF_OpenFont: %s\n", TTF_GetError());
  }

  SDL_Color fontColor = {255, 255, 255};
  SDL_Surface *surfaceText = TTF_RenderText_Solid(theFont, "Hello", fontColor);
  SDL_Texture *textureText = SDL_CreateTextureFromSurface(renderer, surfaceText);
  SDL_FreeSurface(surfaceText);

  SDL_Rect fontRect;
  fontRect.x = 10;
  fontRect.y = 10;
  fontRect.w = 60;
  fontRect.h = 30;

  int running = 1;
  Player player(200, 300);
  Wizard wizard(200, 200);
  Wizard wizard2(200, 250);

  while (running) {
    while (SDL_PollEvent(&event)) {
      running = quitGame(running, window, event);
      // player.move(event);
      // checkVicinity(player, wizard, event);
      if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == SDLK_b) {
          fontRect.x += 10;
        }
        if (event.key.keysym.sym == SDLK_h) {
          fontRect.w = 0;
        }
        if (event.key.keysym.sym == SDLK_g) {
          fontRect.w = 60;
        }
      }
    }

    drawBackground(renderer);
    SDL_RenderCopy(renderer, textureText, NULL, &fontRect);

    player.draw(renderer);
    wizard.draw(renderer);
    wizard2.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_DestroyTexture(textureText);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}

int quitGame(int running, SDL_Window *window, SDL_Event &event) {
  switch (event.type) {
    case SDL_QUIT:
    case SDL_WINDOWEVENT_CLOSE:
      running = 0;
      if (window)
        window = NULL;
      break;
  }
  return running;
}

void drawBackground(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
}

void checkVicinity(Player player, Wizard wizard, SDL_Event &event) {
  if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_a) {
      player.getPos();
      wizard.getPos();
    }
  }
}
