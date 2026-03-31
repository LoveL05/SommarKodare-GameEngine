#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL3/SDL.h>
#include <set>
#include "input.h"
#include "window.h"
#include "texture.h"
#include "audio_player.h"
#include "updateable.h"

class Engine {
public:
    bool IsRunning();
    void SetRunning(bool running);
    int Run();
    void Stop();
    void Update();
    void LateUpdate();
    void Event(SDL_Event* Event);
    void AddUpdateable(Updateable *updateable);
    void AddStartable(Startable *startable);
    
    InputSystem &getInputSystem();

    Engine(const char* title, int width, int height);
    ~Engine();
    
private:
    std::string_view m_title;
    int m_defaultWidth, m_defaultHeight;
    
    InputSystem m_inputSystem;
    static bool m_running;
    Window* m_window = nullptr;
    std::set<Updateable *> m_updateables;
    std::set<Startable *> m_startables;
};

#endif /* ENGINE_H_ */