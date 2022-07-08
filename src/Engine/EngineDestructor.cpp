#include <Engine.h>

Engine::~Engine() {
    delete _Window;
    SDL_Quit();
}