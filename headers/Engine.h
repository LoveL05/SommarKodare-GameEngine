#ifndef ENGINE_H_
#define ENGINE_H_

#include <SDL3/SDL.h>
#include <set>
#include <Input.h>
#include <Window.h>
#include <Texture.h>
#include <AudioPlayer.h>

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

#endif /* ENGINE_H_ */