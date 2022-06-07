#include <SDL2/SDL_ttf.h>
#include "main.hpp"

int main(int arc, char *argv[]) {
  initialize();

  SDL_Window *window = initWindow("Clean Story", 640, 480);
  SDL_Renderer *renderer = initRenderer(window);
  TTF_Font *theFont = TTF_OpenFont("assets/fonts/Comfortaa[wght].ttf", 20);
  SDL_Event event;

  Story story;
  Game game;
  Player player;
  Home home;
  Menu menu;
  // Button buttons[3];
  Button button1;
  Button button2;
  Button button3;
  Theme themes;
  Screen screens[3];
  // Music song("assets/audio/phased.mp3");
  Chunk song1("assets/audio/beep.wav");
  // Portal portal;
  Animation animation;

  for (int s = 0; s < 3; s++) {
    screens[s].prepareDialog(theFont, renderer);
    screens[s].setColor(themes.getColor(s));
  }

  home.setText(theFont, renderer);
  menu.setText(theFont, renderer);

  const char *button1Text[] = {"M", "Talk"};
  button1.setText(theFont, button1Text, renderer);

  const char *button2Text[] = {"G", "Take"};
  button2.setText(theFont, button2Text, renderer);

  const char *button3Text[] = {"H", "Enter"};
  button3.setText(theFont, button3Text, renderer);

  pos wizardPos;
  pos itemPos;
  pos portalPos;

  while (game.running) {
    while (SDL_PollEvent(&event)) {
      game.running = quitGame(game.running, window, event);
      game.current = screens[game.active].setCurrent(event, game.current);
      game.handleKeyDown(event);
      player.move(event);
      player.pickupItem(
        event,
        screens[game.active].wizard->hat,
        screens[game.active],
        renderer,
        theFont
      );

      switch (event.type) {
        case SDL_KEYDOWN:
          if (event.key.keysym.sym == SDLK_p)
            song1.play();
          break;
      }
    }

    wizardPos = screens[game.active].wizard->getPosition();
    game.nearEntity = player.getVicinity(wizardPos.x, wizardPos.y);

    itemPos = screens[game.active].wizard->getHatPosition();
    game.nearItem = player.getVicinity(itemPos.x, itemPos.y);

    portalPos = screens[game.active].portal.getPosition();
    game.nearPortal = player.getVicinity(portalPos.x, portalPos.y);

    if (game.state == "home") {
      home.draw(renderer);
    } else if (game.state == "menu") {
      menu.draw(renderer);
    } else {
      screens[game.active].draw(renderer, game.nearEntity, game.current);
      player.draw(renderer);
    }

    if (game.nearEntity)
      button1.draw(renderer);

    if (game.nearItem)
      button2.draw(renderer);

    if (game.nearPortal)
      button3.draw(renderer);

    // if (story.tasks[0].completed)
    //   portal.draw(renderer);

    // animation.draw(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  TTF_CloseFont(theFont);
  SDL_Quit();
  return 0;
}
