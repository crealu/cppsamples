// #include <SDL2/SDL.h>
// #include <SDL2/SDL_ttf.h>
// #include "../../headers/SDL_image.h"

class Spin {
public:
  Spin();
  ~Spin();
  void draw(SDL_Renderer *renderer);
  void setText(TTF_Font *font, SDL_Renderer *renderer);
  void setAngle();

protected:
  SDL_Rect rect;
  SDL_Surface *surface;
  SDL_Texture *texture;
  const char *text;
  double degrees;
  SDL_Point *center;
  SDL_RendererFlip flip;
};
