#include <cstdio>

#include "window.h"

SDL_Window* Window::getWindow() {
    return m_window;
}

SDL_Surface* Window::getSurface() {
    return m_surface ? m_surface : (m_surface = SDL_GetWindowSurface(m_window));
}

SDL_Renderer* Window::getRenderer() {
    return m_renderer;
}

Window::Window(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title, width, height, SDL_WINDOW_RESIZABLE);

    if (!m_window) {
        printf("SDL_CreateWindow: %s\n", SDL_GetError());
        return;
    }

    if (!(m_renderer = SDL_CreateRenderer(m_window, NULL))) {
        printf("SDL_CreateRenderer: %s\n", SDL_GetError());
        return;
    }

    SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "opengl");
    m_surface = SDL_GetWindowSurface(m_window);
    if (!m_surface) {
        SDL_SetHint(SDL_HINT_FRAMEBUFFER_ACCELERATION, "1");
        m_surface = SDL_GetWindowSurface(m_window);
    }

    if (!(m_surface = SDL_GetWindowSurface(m_window))) {
        printf("SDL_GetWindowSurface: %s\n", SDL_GetError());
        return;
    }
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
    SDL_DestroySurface(m_surface);
    SDL_DestroyRenderer(m_renderer);
}
