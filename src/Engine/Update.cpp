#include <Engine.h>

void Engine::Update() {
    SDL_UpdateWindowSurface(_Window->GetWindow());
}