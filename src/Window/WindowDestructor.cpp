#include <Window.h>

Window::~Window() {
    SDL_DestroyWindow(_Window);
    SDL_FreeSurface(_Surface);
    SDL_DestroyRenderer(_Renderer);
}