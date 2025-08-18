add_library(game STATIC game.cpp)
target_include_directories(game PUBLIC "${3dX_SOURCE_DIR}/game")
target_link_libraries(game PUBLIC engine)
