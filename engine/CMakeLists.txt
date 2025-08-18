file(GLOB_RECURSE ENGINE_SRC "./*.cpp" )

add_library(engine SHARED ${ENGINE_SRC})
target_include_directories(engine PUBLIC "${3dX_SOURCE_DIR}")
target_link_libraries(engine PUBLIC vendor)
