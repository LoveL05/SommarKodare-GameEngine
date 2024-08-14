#include "Core/CoreL.hpp"

int main(int argv, char** args)
{
    WindowL *window = new WindowL(
        "Engine V1",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        (uint) 640, (uint) 520,
        0, 0
    );
    EngineCore engine = EngineCore(window);
    return engine.run();
}
