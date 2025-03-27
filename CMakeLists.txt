cmake_minimum_required(VERSION 3.30.0)
project(3dX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(3dX main.cpp)

add_subdirectory(core)
target_include_directories(3dX PUBLIC "${3dX_SOURCE_DIR}/core/renderer")
target_link_libraries(3dX PUBLIC core)

