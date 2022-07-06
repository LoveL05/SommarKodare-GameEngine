#ifndef C2A1C30C_2613_4CD9_B85A_E64F7B4C7016
#define C2A1C30C_2613_4CD9_B85A_E64F7B4C7016

#include <SDL2/SDL.h>

class Engine {
    private:
        bool _Running = true;
    public:
        bool IsRunning();
        void SetRunning(bool running);
        void Stop();
        void Update();
        void LateUpdate();
        void Event(SDL_Event* Event);
    public:
        Engine(const char* title, int width, int height);
        ~Engine();
};

#endif /* C2A1C30C_2613_4CD9_B85A_E64F7B4C7016 */