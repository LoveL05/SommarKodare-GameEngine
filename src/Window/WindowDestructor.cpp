#include <Window.h>

Window::~Window() {
    SDL_DestroyWindow(_Window);
    SDL_DestroyRenderer(_Renderer);
    SDL_FreeSurface(_Surface);
}