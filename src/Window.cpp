#include <cstdio>

#include "Window.h"

SDL_Window* Window::GetWindow() {
    return _Window;
}

SDL_Surface* Window::GetSurface() {
    return _Surface ? _Surface : (_Surface = SDL_GetWindowSurface(_Window));
}

SDL_Renderer* Window::GetRenderer() {
    return _Renderer;
}

Window::Window(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Init: %s\n", SDL_GetError());
        return;
    }

    _Window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);

    if (!_Window) {
        printf("SDL_CreateWindow: %s\n", SDL_GetError());
        return;
    }

    if (!(_Renderer = SDL_CreateRenderer(_Window, NULL))) {
        printf("SDL_CreateRenderer: %s\n", SDL_GetError());
        return;
    }

    SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "opengl");
    _Surface = SDL_GetWindowSurface(_Window);
    if (!_Surface) {
        SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "1");
        _Surface = SDL_GetWindowSurface(_Window);
    }

    if (!(_Surface = SDL_GetWindowSurface(_Window))) {
        printf("SDL_GetWindowSurface: %s\n", SDL_GetError());
        return;
    }
}

Window::~Window() {
    SDL_DestroyWindow(_Window);
    SDL_DestroySurface(_Surface);
    SDL_DestroyRenderer(_Renderer);
}
