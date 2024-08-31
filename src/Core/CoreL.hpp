#ifndef CORE_ENGINE_HPP
#define CORE_ENGINE_HPP

#include <set>
#include <memory>
#include <SDL2/SDL.h>
#include "../Window/WindowL.hpp"
#include "../Objects/Counter.hpp"
#include "../UpdateableObject/UpdateableObject.hpp"

template<typename T> 
concept Updateable = requires (T t) { std::is_base_of<UpdateableObject, T>::value; };
class EngineCore {

    std::set<UpdateableObject *> m_updateables;
    WindowL *m_window;

    
    bool m_shouldQuit = false;

public:
    EngineCore(WindowL *window);
    virtual ~EngineCore();

    int run();
    void stop();

    template <Updateable T> void addUpdateable(T &updateable) {
        m_updateables.insert(&updateable);
    };
};

#endif