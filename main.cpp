#include "renderer.h"
#include <iostream>

using namespace std;

int main() {
  cout << "Hello World!" << endl;
  NRENDERER::Renderer renderer;
  renderer.setWidth(100);
  cout << renderer.getWidth() << endl;
  NRENDERER::Renderer::Render();

  return 0;
}
