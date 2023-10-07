#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

int SDL_main(int argc, char** argv) {
    if (argc == 1) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 1){
            printf("An error occurred while initializing SDL: %s\n", SDL_GetError());
        }
        SDL_Window *window = SDL_CreateWindow("Hello, World!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
        //SDL_Surface *surface = SDL_GetWindowSurface(window);
        //SDL_FreeSurface(surface);
        //SDL_DestroyWindow(window);
        //SDL_Quit();
    }
    //printf("Hello, World!\n");
    return 0;
}
