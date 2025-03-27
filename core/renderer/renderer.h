#ifndef RENDERER_H
#define RENDERER_H

namespace NRENDERER {

class Renderer {
private:
  int width;
  int height;
  // Methods

public:
  Renderer();
  Renderer(int width, int height);

  void setWidth(int);
  int getWidth();

  static void Render();
};
} // namespace NRENDERER

#endif
