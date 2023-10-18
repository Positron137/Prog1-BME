#include "main.h"

int main(int argc, char** argv) {
    char *theme_file = "theme.ini";
    char *input_file = "test.c";
    char *output_file = "test";
    theme_t *theme = (theme_t *)malloc(sizeof (theme_t));
    file_type_e output_type;
    file_type_e input_type;
    int quit = 0;
    HWND windowRef;
    SDL_Event event;

    if (argc != 1){
        if(init_console(argc, argv, theme_file, output_file, input_file) == -1) return -1;
        output_type = ends_with(output_file);
        input_type = ends_with(input_file);
    }
    if (read_ini(theme_file, theme) == -1) theme = &default_theme;
    SDL_Window *window = SDL_CreateWindow("Source to Flow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    windowRef = GetHwnd(window);
    ActivateMenu(windowRef);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface *surface = SDL_CreateRGBSurface(1,640,480,32,0,0,0,0);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);

    while (!quit) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE:
                event.type = SDL_QUIT;
                SDL_PushEvent(&event);
                break;
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_SYSWMEVENT:
                if (event.syswm.msg->msg.win.msg == WM_COMMAND){
                    switch (event.syswm.msg->msg.win.wParam){
                        case ID_EXIT:
                            quit = 1;
                            break;
                        case ID_OPEN_FILE:
                            IFileOpenDialog *file_dialog = IFileOpenDialog_Create();
                            break;
                        case ID_SAVE_FLOW:
                            break;
                        case ID_LOAD_THEME:
                            break;
                        case ID_RESET_THEME:
                            theme = &default_theme;
                            break;
                        case ID_ZOOM_IN:
                            break;
                        case ID_ZOOM_OUT:
                            break;
                        case ID_ZOOM_RESET:
                            break;
                        default:
                            break;
                    }
                }
                break;
        }
        SDL_SetRenderDrawColor(renderer, theme->main_.background.r, theme->main_.background.g, theme->main_.background.b, theme->main_.background.a);
        /*SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);*/
        SDL_RenderPresent(renderer);
    }
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

void ActivateMenu(HWND windowRef)
{
    HMENU hMenuBar = CreateMenu();
    HMENU hFile = CreateMenu();
    HMENU hView = CreateMenu();

    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hFile, "File");
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hView, "View");
    AppendMenu(hMenuBar, MF_STRING, ID_EXIT, "Exit");

    AppendMenu(hFile, MF_STRING, ID_OPEN_FILE, "Open File");
    AppendMenu(hFile, MF_STRING, ID_SAVE_FLOW, "Save flowchart");

    AppendMenu(hView, MF_STRING, ID_LOAD_THEME, "Load Theme");
    AppendMenu(hView, MF_STRING, ID_RESET_THEME, "Reset Theme");
    AppendMenu(hView, MF_STRING, ID_ZOOM_IN, "Zoom In");
    AppendMenu(hView, MF_STRING, ID_ZOOM_OUT, "Zoom Out");
    AppendMenu(hView, MF_STRING, ID_ZOOM_RESET, "Zoom Reset");



    SetMenu(windowRef, hMenuBar);
}
