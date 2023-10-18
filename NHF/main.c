#include "main.h"

file_type_e DEFAULT_FILE_TYPE = file_type_png;

int main(int argc, char** argv) {
    char *theme_file = "theme.ini";
    char *input_file = "test.c";
    char *output_file = "test";
    theme_t *theme = (theme_t *)malloc(sizeof (theme_t));
    file_type_e output_type;
    file_type_e input_type;

    if (argc != 1){
        if(init_console(argc, argv, theme_file, output_file, input_file) == -1) return -1;
        output_type = ends_with(output_file);
        input_type = ends_with(input_file);
    }
    read_ini(theme_file, theme);
    SDL_Window *window = SDL_CreateWindow("Source to Flow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_Surface *surface = SDL_CreateRGBSurface(1,640,480,32,0,0,0,0);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Event event;
    AttachMenu(window);
    while (1) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                goto end;
            /*case SDL_WINDOWEVENT_RESIZED:
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
                break;*/
        }
        SDL_SetRenderDrawColor(renderer, theme->main_.background.r, theme->main_.background.g, theme->main_.background.b, theme->main_.background.a);
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    end:
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    return 0;
}

HWND GetHwnd(SDL_Window *window){
    SDL_SysWMinfo windowInfo;
    if(!SDL_GetWindowWMInfo(window,&windowInfo)) return NULL;
    return windowInfo.info.win.window;
}

void AttachMenu(SDL_Window *window){
    HWND hwnd = GetHwnd(window);
    HMENU menu = CreateMenu();
    SetMenu(hwnd, menu);
}