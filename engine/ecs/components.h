#include "SDL3/SDL_render.h"

struct Position {
  float x;
  float y;
};

struct Velocity {
  float x;
  float y;
};

struct Texture {
  SDL_Texture *texture;
};

struct Rect {
  float x;
  float y;
  float w;
  float h;
};

struct RendererResource {
  SDL_Renderer *renderer;
};
