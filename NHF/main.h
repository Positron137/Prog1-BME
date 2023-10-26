//
// Created by sziha on 18/10/2023.
//

#ifndef NHF_MAIN_H
#define NHF_MAIN_H
#endif//NHF_MAIN_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "console.h"
#include "ini_reader.h"
#include <windows.h>
#include <SDL_syswm.h>
#include <shobjidl.h>
#include "source_reader.h"
#include "debugmalloc.h"

int main(int argc, char** argv);

#define ID_OPEN_FILE 1
#define ID_SAVE_FLOW 2
#define ID_LOAD_THEME 3
#define ID_RESET_THEME 4
#define ID_ZOOM_IN 5
#define ID_ZOOM_OUT 6
#define ID_ZOOM_RESET 7
#define ID_EXIT 8

/**
 * Gets win32 window handle
 * @param window sdl window
 * @return win32 window handle
 */
HWND GetHwnd(SDL_Window *window);
/**
 * Creates a menu for the given window handle
 * @param windowRef win32 window handle
 */
void ActivateMenu(HWND windowRef);
//code from https://stackoverflow.com/questions/51250046/sdl2-win32-api-menubar-click-event-not-working
char* file_open_dialog(HWND windowRef);
char* file_save_dialog(HWND windowRef);

static theme_t default_theme = {
        .main_ = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}},
        .functions = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}},
        .structs = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}},
        .variables = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}},
        .conditionals = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}},
        .loops = {
            .background = {.r = 255,.g = 255,.b = 255,.a = 255},
            .text = {.r = 0,.g = 0,.b = 0,.a = 255}}
};
