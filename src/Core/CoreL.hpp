#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include <SDL2/SDL.h>
#include "../Window/WindowL.hpp"

class EngineCore {

private:
    WindowL *m_window;

    bool m_shouldQuit;
public:
    EngineCore(WindowL *window);
    virtual ~EngineCore();

    int run();
    void stop();
};

#endif