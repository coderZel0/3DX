#include <unordered_map>
#include <memory>
#include "SDL3/SDL_render.h"
#include "SDL3_image/SDL_image.h"

template <typename T> class ResourceManager {

protected:
  std::unordered_map<const char*, std::shared_ptr<T>> resources;
  SDL_Renderer *renderer;
  // static std::string resourcePath;

public:
  ResourceManager(SDL_Renderer *renderer): renderer(renderer) {};
  ~ResourceManager(){};

  virtual std::shared_ptr<T> loadResource(const char *resourceName)=0;
  virtual void unloadResource(const char *resourceName)=0;
};


class TextureResourceManager : public ResourceManager<SDL_Texture> {
  public:
    TextureResourceManager(SDL_Renderer *renderer): ResourceManager<SDL_Texture>(renderer) {};
    ~TextureResourceManager() {};
    std::shared_ptr<SDL_Texture> loadResource(const char *resourceName) override;
    void unloadResource(const char *resourceName) override;
};
