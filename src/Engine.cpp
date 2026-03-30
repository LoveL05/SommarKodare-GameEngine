#include <Engine.h>

bool Engine::_Running = true;

Engine::Engine(const char* title, int width, int height) {
    _Window = new Window(title, width, height);
    Input = InputSystem();
    _Running = true;

    SDL_UpdateWindowSurface(_Window->GetWindow());
    SDL_SetRenderLogicalPresentation(_Window->GetRenderer(), width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    Sound* waluigi = new Sound("waluigi.wav");
    waluigi->SetupDevice();
    waluigi->PlaySound();
    
    SDL_Event event;
    while (_Running) {
        Event(&event);
        Update();

        LateUpdate();
    }

    delete waluigi;
}

Engine::~Engine() {
    delete _Window;
    SDL_Quit();
}

void Engine::Event(SDL_Event* Event) {
    Input.ButtonsJustPressed.clear();
    Input.ButtonsJustReleased.clear();
    while (SDL_PollEvent(Event)) {
        switch (Event->type)
        {
        case SDL_EVENT_QUIT:
            Stop();
            break;
        case SDL_EVENT_KEY_DOWN:
            Input.ButtonPressed(Event->key.raw);
            break;
        case SDL_EVENT_KEY_UP:
            Input.ButtonReleased(Event->key.raw);
            break;
        default:
            break;
        }
    }
}

void Engine::LateUpdate() {
    
}

bool Engine::IsRunning() {
    return _Running;
}

void Engine::SetRunning(bool Running) {
    if (!Running) {
        Stop();
    }
}

void Engine::Stop() {
    _Running = false;
}

void Engine::Update() {
    if (Texture2D::GetInstances().size() > 0) {
        SDL_RenderClear(_Window->GetRenderer());
        for (Texture2D* t : Texture2D::GetInstances()) {
            SDL_RenderTexture(_Window->GetRenderer(), t->GetTexture(), t->Size(), t->Position());
        }
        SDL_RenderPresent(_Window->GetRenderer());
    }
}
