#include <iostream>
#include <set>
#include "Core/CoreL.hpp"

int main(int argv, char** args)
{
    EngineCore engine = EngineCore(new WindowL("Sommar Kodare", 0, 0, 640, 520, SDL_WINDOW_RESIZABLE, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    return engine.run();
}
