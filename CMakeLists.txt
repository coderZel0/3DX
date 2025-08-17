cmake_minimum_required(VERSION 3.30.0)
set(CMAKE_CXX_COMPILER "C:\\mingw64\\bin\\g++.exe")
set(CMAKE_C_COMPILER "C:\\mingw64\\bin\\gcc.exe")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

project(3dX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${3dX_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${3dX_SOURCE_DIR}/lib")

# prevent installing to system directories.
set(CMAKE_INSTALL_PREFIX "${3dX_SOURCE_DIR}" CACHE INTERNAL "")
set(CMAKE_PREFIX_PATH "${3dX_SOURCE_DIR}/vendor/SDL")

add_executable(3dX main.cpp)

add_subdirectory(core)
target_link_libraries(${PROJECT_NAME} PUBLIC core)

add_subdirectory(vendor)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor)

