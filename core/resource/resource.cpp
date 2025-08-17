#include "resource.h"
#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"
#include <filesystem>
#include <memory>

std::shared_ptr<SDL_Texture>
TextureResourceManager::loadResource(const char *resourceName) {
  auto it = resources.find(resourceName);
  if (it != resources.end()) {
    // Resource already loaded, return it
    return std::static_pointer_cast<SDL_Texture>(it->second);
  }
  // Load the resource and store it in the map
  const std::filesystem::path path =
      std::filesystem::current_path() / "assets" / "textures" / resourceName;

  SDL_Surface *surface = IMG_Load(path.string().c_str());
  if (!surface) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't create surface from image: %s", SDL_GetError());
    return nullptr;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                 "Couldn't create texture from surface: %s", SDL_GetError());
    return nullptr;
  }

  auto texturePtr = std::shared_ptr<SDL_Texture>(
      texture, [](SDL_Texture *tex) { SDL_DestroyTexture(tex); });

  SDL_DestroySurface(surface);
  resources[resourceName] = texturePtr;
  return texturePtr;
}

void TextureResourceManager::unloadResource(const char *name) {
} // unload resources in a loop and call in destructor
