cmake_minimum_required(VERSION 3.26)
project(NHF C)

set(CMAKE_C_STANDARD 11)
set(TARGET_NAME NHF)
add_executable(${TARGET_NAME} main.c
        console.h
        console.c
        ini_reader.c
        ini_reader.h
        main.h
        source_reader.c
        source_reader.h
        debugmalloc.h)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2GFX REQUIRED SDL2_gfx)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2GFX_INCLUDE_DIRS} ${SDL2TTF_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2GFX_LIBRARIES} ${SDL2TTF_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
target_compile_options(${TARGET_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)