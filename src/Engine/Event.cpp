#include <Engine.h>

void Engine::Event(SDL_Event* Event) {
    while (SDL_PollEvent(Event)) {
        switch (Event->type)
        {
        case SDL_QUIT:
            Stop();
            break;
        default:
            break;
        }
    }
}