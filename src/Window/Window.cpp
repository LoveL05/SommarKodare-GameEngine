#include <Window.h>

Window::Window(const char* title, int width, int height) {
    _Window = SDL_CreateWindow(
        title, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        width, 
        height, 
        SDL_WINDOW_RESIZABLE
    );
};

Window::~Window() {
    SDL_DestroyWindow(_Window);
    printf("Destroyed\n");
}

bool Window::IsOpen() {    return _Window;   }

SDL_Window* Window::GetWindow() {
    return _Window;
}