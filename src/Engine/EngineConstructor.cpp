#include <Engine.h>

Engine::Engine(const char* title, int width, int height) {
    _Window = new Window(title, width, height);
    Input = InputSystem();
    _Running = true;

    SDL_UpdateWindowSurface(_Window->GetWindow());

    SDL_Event* event;

    Sound* waluigi = new Sound("./waluigi.wav");
    waluigi->SetupDevice();

    while (_Running) {
        Event(event);
        Update();

        if (Input.IsButtonJustPressed(SDLK_SPACE)) {
            waluigi->PlaySound();
        }

        LateUpdate();
    }

    delete waluigi;
}