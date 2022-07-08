#include <Engine.h>

bool Engine::_Running = true;

bool Engine::IsRunning() {
    return _Running;
}

void Engine::SetRunning(bool Running) {
    if (!Running) {
        Stop();
    }
}