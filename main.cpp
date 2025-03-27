#include "SDL3/SDL.h"
#include "SDL3/SDL_log.h"
#include "renderer.h"
#include <iostream>

using namespace std;

int main() {
  SDL_Log("%s", "HELLO SDL");
  NRENDERER::Renderer renderer;
  renderer.setWidth(100);
  cout << renderer.getWidth() << endl;
  NRENDERER::Renderer::Render();

  return 0;
}
