#ifndef C2A1C30C_2613_4CD9_B85A_E64F7B4C7016
#define C2A1C30C_2613_4CD9_B85A_E64F7B4C7016

#include <SDL2/SDL.h>
#include <Input.h>
#include <Window.h>

class Engine {
    private:
        static bool _Running;
        Window* _Window = nullptr;
    public:
        bool IsRunning();
        void SetRunning(bool running);
        void Stop();
        void Update();
        void LateUpdate();
        void Event(SDL_Event* Event);

        InputSystem Input;
    public:
        Engine(const char* title, int width, int height);
        ~Engine();
};

#endif /* C2A1C30C_2613_4CD9_B85A_E64F7B4C7016 */