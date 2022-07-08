#include <Window.h>

SDL_Window* Window::GetWindow() {
    return _Window;
}

SDL_Renderer* Window::GetRenderer() {
    return _Renderer;
}

SDL_Surface* Window::GetSurface() {
    return _Surface ? _Surface : (_Surface = SDL_GetWindowSurface(_Window));
}