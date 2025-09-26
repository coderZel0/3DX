#pragma once
#include <fstream>
#include <memory.h>
#include <string>
#include <unordered_map>

class AssetManifest {
private:
  std::unordered_map<std::string, std::string> assets;
  const std::string manifestPath = "assets/asset_manifest.json";

public:
  void loadManifest() { std::ifstream file(manifestPath); }
  void addAsset(const std::string &name, const std::string &path) {
    assets[name] = path;
  }
};
