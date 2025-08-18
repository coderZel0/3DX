include(FetchContent)

set(LIBS)

set(SDL_TEST OFF)

set(SDLIMAGE_VENDORED OFF)
set(SDLIMAGE_AVIF OFF) # disable formats we don't use to make the build faster and smaller.
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_WEBP OFF)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

add_subdirectory(SDL)

#add flecs fetch from origin
FetchContent_Declare(
  flecs
  GIT_REPOSITORY https://github.com/SanderMertens/flecs.git
  GIT_TAG v4.1.0
)

set(FLECS_BUILD_EXAMPLES OFF)
set(FLECS_BUILD_TESTING OFF)
set(FLECS_BUILD_DOCS OFF)
FetchContent_MakeAvailable(flecs)

list(APPEND LIBS SDL3_image::SDL3_image SDL3::SDL3 flecs::flecs_static)

add_library(vendor INTERFACE)
target_include_directories(vendor INTERFACE "${3dX_SOURCE_DIR}/vendor")
target_link_libraries(vendor INTERFACE ${LIBS})
