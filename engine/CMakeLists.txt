file(GLOB_RECURSE ENGINE_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )

add_library(engine SHARED ${ENGINE_SRC})
target_include_directories(engine PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(engine PUBLIC vendor flecs::flecs_static)
