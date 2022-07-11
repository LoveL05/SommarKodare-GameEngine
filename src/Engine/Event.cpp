#include <Engine.h>

void Engine::Event(SDL_Event* Event) {
    Input.ButtonsJustPressed.clear();
    Input.ButtonsJustReleased.clear();
    while (SDL_PollEvent(Event)) {
        switch (Event->type)
        {
        case SDL_QUIT:
            Stop();
            break;
        case SDL_KEYDOWN:
            Input.ButtonPressed(Event->key.keysym.sym);
            break;
        case SDL_KEYUP:
            Input.ButtonReleased(Event->key.keysym.sym);
            break;
        default:
            break;
        }
    }
}