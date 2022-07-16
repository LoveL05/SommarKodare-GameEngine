#ifndef A8E646D8_EB5F_4149_8007_EE8C714CC18E
#define A8E646D8_EB5F_4149_8007_EE8C714CC18E

#include <SDL2/SDL.h>

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

#endif /* A8E646D8_EB5F_4149_8007_EE8C714CC18E */
