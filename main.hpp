#include <SDL2/SDL.h>
#include "components/player.cpp"
#include "components/circle.cpp"
#include "components/screen.cpp"

int quitGame(int running, SDL_Window *window, SDL_Event &event);
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

// int getLength(string str);
// int getLength(string str) {
//   return sizeof(str)/sizeof(str[0]);
// }
