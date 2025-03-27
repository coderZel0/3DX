cmake_minimum_required(VERSION 3.30.0)
project(3dX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(3dX main.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${3dX_SOURCE_DIR}")

add_subdirectory(core)
target_include_directories(3dX PUBLIC "${3dX_SOURCE_DIR}/core/renderer")
target_link_libraries(3dX PUBLIC core)

add_subdirectory(vendor)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

