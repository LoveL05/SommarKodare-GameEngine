#include <Engine.h>

bool Engine::_Running = true;

Engine::Engine(const char* title, int width, int height) : m_title(title), m_defaultWidth(width), m_defaultHeight(height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Init: %s\n", SDL_GetError());
        return;
    }
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

        for (auto i : this->m_updateables) {
            i->OnUpdate();
        }

        SDL_RenderPresent(_Window->GetRenderer());
    }
}

void Engine::AddUpdateable(Updateable *updateable) {
    this->m_updateables.insert(updateable);
}

void Engine::AddStartable(Startable *startable) {
    this->m_startables.insert(startable);
}

int Engine::Run() {
    _Window = new Window(this->m_title.cbegin(), this->m_defaultWidth, this->m_defaultHeight);
    Input = InputSystem();
    _Running = true;

    SDL_UpdateWindowSurface(_Window->GetWindow());
    // SDL_SetRenderLogicalPresentation(_Window->GetRenderer(), this->m_defaultWidth, this->m_defaultHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    for (auto i : this->m_startables) {
        i->OnStart();
    }

    SDL_Event event;
    while (_Running) {
        Event(&event);
        Update();

        LateUpdate();
    }

    return 0;
}
