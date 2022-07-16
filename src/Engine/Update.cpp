#include <Engine.h>

void Engine::Update() {
    if (Texture2D::GetInstances().size() > 0) {
        SDL_RenderClear(_Window->GetRenderer());
        for (Texture2D* t : Texture2D::GetInstances()) {
            SDL_RenderCopy(_Window->GetRenderer(), t->GetTexture(), t->Size(), t->Position());
        }
        SDL_RenderPresent(_Window->GetRenderer());
    }
}