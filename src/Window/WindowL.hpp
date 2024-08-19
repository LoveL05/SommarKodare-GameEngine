#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <optional>

class WindowL {
private:
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;

public:
    WindowL(const char *title, uint x, uint y, uint w, uint h, uint windowFlags, uint rendererFlags);
    virtual ~WindowL();

    SDL_Window *getNativeWindow();
    SDL_Renderer *getNativeRenderer();
};

struct WindowProperties {
    const char *title;
    uint x, y, w, h;
};

#endif