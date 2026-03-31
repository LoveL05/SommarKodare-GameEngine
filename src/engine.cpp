#include "engine.h"

bool Engine::m_running = true;

Engine::Engine(const char* title, int width, int height) : m_title(title), m_defaultWidth(width), m_defaultHeight(height) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        printf("Init: %s\n", SDL_GetError());
        return;
    }
}

Engine::~Engine() {
    delete m_window;
    SDL_Quit();
}

void Engine::Event(SDL_Event* Event) {
    m_inputSystem.m_buttonsJustPressed.clear();
    m_inputSystem.m_buttonsJustReleased.clear();
    while (SDL_PollEvent(Event)) {
        switch (Event->type)
        {
        case SDL_EVENT_QUIT:
            Stop();
            break;
        case SDL_EVENT_KEY_DOWN:
            m_inputSystem.buttonPressed(Event->key.raw);
            break;
        case SDL_EVENT_KEY_UP:
            m_inputSystem.buttonReleased(Event->key.raw);
            break;
        default:
            break;
        }
    }
}

void Engine::LateUpdate() {
    
}

bool Engine::IsRunning() {
    return m_running;
}

void Engine::SetRunning(bool Running) {
    if (!Running) {
        Stop();
    }
}

void Engine::Stop() {
    m_running = false;
}

void Engine::Update() {
    if (Texture2D::getInstances().size() > 0) {
        SDL_RenderClear(m_window->getRenderer());

        for (Texture2D* t : Texture2D::getInstances()) {
            SDL_RenderTexture(m_window->getRenderer(), t->getTexture(), t->getSize(), t->getPosition());
        }

        for (auto i : this->m_updateables) {
            i->onUpdate();
        }

        SDL_RenderPresent(m_window->getRenderer());
    }
}

void Engine::AddUpdateable(Updateable *updateable) {
    this->m_updateables.insert(updateable);
}

void Engine::AddStartable(Startable *startable) {
    this->m_startables.insert(startable);
}

int Engine::Run() {
    m_window = new Window(this->m_title.cbegin(), this->m_defaultWidth, this->m_defaultHeight);
    m_inputSystem = InputSystem();
    m_running = true;

    SDL_UpdateWindowSurface(m_window->getWindow());
    // SDL_SetRenderLogicalPresentation(m_window->getRenderer(), this->m_defaultWidth, this->m_defaultHeight, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    
    for (auto i : this->m_startables) {
        i->onStart();
    }

    SDL_Event event;
    while (m_running) {
        Event(&event);
        Update();

        LateUpdate();
    }

    return 0;
}
