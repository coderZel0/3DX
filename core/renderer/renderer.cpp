#include "renderer.h"
#include <iostream>

using namespace NRENDERER;

Renderer::Renderer() : width(800), height(600) {}

Renderer::Renderer(int width, int height) : width(width), height(height) {}

void Renderer::Render() { std::cout << "Renderering" << std::endl; }

void Renderer::setWidth(int w) {
  this->width = w;
  std::cout << "width set to" << w << std::endl;
}

int Renderer::getWidth() { return this->width; }
