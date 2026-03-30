#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL3/SDL.h>

class Window {
    private:
        SDL_Window* _Window = nullptr;
        SDL_Surface* _Surface = nullptr;
        SDL_Renderer* _Renderer = nullptr;
    public:
        SDL_Window* GetWindow();
        SDL_Surface* GetSurface();
        SDL_Renderer* GetRenderer();
        Window(const char* title, int width, int height);
        ~Window();
};

#endif /* WINDOW_H_ */
