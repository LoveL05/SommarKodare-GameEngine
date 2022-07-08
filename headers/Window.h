#ifndef A8E646D8_EB5F_4149_8007_EE8C714CC18E
#define A8E646D8_EB5F_4149_8007_EE8C714CC18E

#include <SDL2/SDL.h>
#include <set>
#include <iostream>

class Window {
    private:
        SDL_Window* _Window;
        SDL_Renderer* _Renderer;
        SDL_Surface* _Surface;
    public:
        SDL_Window* GetWindow();
        SDL_Renderer* GetRenderer();
        SDL_Surface* GetSurface();
        Window(const char*, int, int);
        ~Window();
};

#endif /* A8E646D8_EB5F_4149_8007_EE8C714CC18E */
