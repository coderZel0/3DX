add_library(core STATIC renderer/renderer.cpp game/game.cpp resource/resource.cpp)
target_include_directories(core PUBLIC "${3dX_SOURCE_DIR}/core")
target_link_libraries(core PUBLIC vendor)
