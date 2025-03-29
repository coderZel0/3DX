cmake_minimum_required(VERSION 3.30.0)
project(3dX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${3dX_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${3dX_SOURCE_DIR}/lib")

# prevent installing to system directories. 
set(CMAKE_INSTALL_PREFIX "${3dX_SOURCE_DIR}" CACHE INTERNAL "")
set(CMAKE_PREFIX_PATH "${3dX_SOURCE_DIR}/vendor/SDL")

add_executable(3dX main.cpp)

add_subdirectory(core)
target_include_directories(${PROJECT_NAME} PUBLIC "${3dX_SOURCE_DIR}/core/renderer")
target_link_libraries(${PROJECT_NAME} PUBLIC core)

add_subdirectory(vendor)
# target_include_directories(${PROJECT_NAME} PRIVATE "${3dX_SOURCE_DIR}/vendor/SDL_image/include")
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

