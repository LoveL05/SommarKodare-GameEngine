#include <Engine.h>

Engine::Engine(const char* title, int width, int height) {
    _Window = new Window(title, width, height);
    _Running = true;

    SDL_Event* event;

    while (_Running) {
        Event(event);
        Update();
        LateUpdate();
    }
}