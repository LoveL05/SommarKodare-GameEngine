#include <Engine.h>
#include <Window.h>

Engine::~Engine() {}

Engine::Engine(const char* title, int width, int height) {
    Window window = Window(title, width, height);
    if (!window.IsOpen()) {printf("Window: ", SDL_GetError()); return;}

    while (IsRunning()) {
        SDL_Event* Event;

        while (SDL_PollEvent(Event)) {
            switch( Event->type ) {
                case SDL_QUIT:
                    Stop();
                    break;
                default:
                    break;
            }
        }

        SDL_UpdateWindowSurface( window.GetWindow() );
    }
}

void Engine::SetRunning(bool Running) {
    _Running = Running;
}

bool Engine::IsRunning() {
    return _Running;
}