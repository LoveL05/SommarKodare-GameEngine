#include "WindowL.hpp"

WindowL::WindowL(const char *title, uint x, uint y, uint w, uint h, uint windowFlags, uint rendererFlags) {
    if (SDL_WasInit(SDL_INIT_VIDEO)) {
        int result = SDL_Init(SDL_INIT_VIDEO);
        if (result < 0) {
            printf("ERROR: %s\n", SDL_GetError());
            return;
        }
    }

    m_window = SDL_CreateWindow("Engine V0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 520, windowFlags);
    m_renderer = SDL_CreateRenderer(m_window, -1, rendererFlags);
}

WindowL::~WindowL() {
    if ( SDL_WasInit(SDL_INIT_VIDEO) ) {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
    }
}

SDL_Renderer *WindowL::getNativeRenderer() {
    return m_renderer;
}

SDL_Window *WindowL::getNativeWindow() {
    return m_window;
}