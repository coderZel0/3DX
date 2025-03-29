set(LIBS)

set(SDL_TEST OFF)

set(SDLIMAGE_VENDORED OFF)
set(SDLIMAGE_AVIF OFF)	# disable formats we don't use to make the build faster and smaller.
set(SDLIMAGE_BMP OFF)
set(SDLIMAGE_WEBP OFF)
add_subdirectory(SDL_image EXCLUDE_FROM_ALL)

add_subdirectory(SDL)

list(APPEND LIBS SDL3_image::SDL3_image SDL3::SDL3)

add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE ${LIBS})
