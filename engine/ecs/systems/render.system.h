#pragma once
#include "ecs/components.h"
#include <flecs.h>

namespace NEngine {

namespace SYSTEMS {

class RenderSystem {
public:
  static void update(flecs::iter &it) {
    auto pos = it.field<Position>(0);
    auto tex = it.field<Texture>(1);
    auto rect = it.field<Rect>(2);

    SDL_Renderer *renderer = it.world().get<RendererResource>().renderer;

    for (int i = 0; i < it.count(); i++) {
      SDL_FRect dst = {rect[i].x, rect[i].y, rect[i].w, rect[i].h};
      SDL_RenderTexture(renderer, tex[i].texture, NULL, &dst);
    }
  }
};

}; // namespace SYSTEMS
}; // namespace NEngine
