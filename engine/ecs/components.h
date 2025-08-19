#include "SDL3/SDL_render.h"

typedef struct {
  float x;
  float y;
} Position;

struct Velocity {
  float x;
  float y;
};

struct Texture {
  SDL_Texture *texture;
};

struct Rect {
  int x;
  int y;
  int w;
  int h;
};
