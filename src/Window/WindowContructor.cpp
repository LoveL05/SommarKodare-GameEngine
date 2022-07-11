#include <Window.h>

Window::Window(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Init: %s\n", SDL_GetError());
        return;
    }

    if (!(_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE))) {
        printf("SDL_CreateWindow: %s\n", SDL_GetError());
        return;
    }
    if (!(_Renderer = SDL_CreateRenderer(_Window, -1, SDL_RENDERER_ACCELERATED))) {
        printf("SDL_CreateRenderer: %s\n", SDL_GetError());
        return;
    }

    if (!(_Surface = SDL_GetWindowSurface(_Window))) {
        printf("SDL_GetWindowSurface: %s\n", SDL_GetError());
        return;
    }
}