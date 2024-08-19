#include "CoreL.hpp"
#include <iostream>

EngineCore::EngineCore(WindowL *window): m_window(window) {

}

EngineCore::~EngineCore() {
    delete m_window;

    m_updateables.erase(std::begin(m_updateables), std::end(m_updateables));

    printf("Updateables: %lu\n", m_updateables.size());
}

int EngineCore::run() {
    if (m_window->getNativeWindow() == nullptr) {
        printf("Unable to load window: %s\n", SDL_GetError());
        return -1;
    }
    
    SDL_Rect screen;
    SDL_Event event;
    while (!m_shouldQuit) {

        while (SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                stop();
                break;
            
            default:
                break;
            }
        }
        SDL_RenderClear(m_window->getNativeRenderer());

        SDL_GetWindowSize(m_window->getNativeWindow(), &screen.w, &screen.h);

        SDL_SetRenderDrawColor(m_window->getNativeRenderer(), 0, 0, 0, 255);
        SDL_RenderFillRect(m_window->getNativeRenderer(), &screen);

        for (auto &updateable : m_updateables) {
            updateable.get()->update();
        }

        SDL_RenderPresent(m_window->getNativeRenderer());
    }

    printf("Rect: %i, %i", screen.h, screen.h);

    return 0;
}

void EngineCore::stop() {
    m_shouldQuit = true;
}

template <Updateable T> 
void EngineCore::addUpdateable(T &updateable) {
    m_updateables.insert(&updateable);
}