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

int main(int argc, char** argv);
HWND GetHwnd(SDL_Window *window);
void AttachMenu(SDL_Window *window);