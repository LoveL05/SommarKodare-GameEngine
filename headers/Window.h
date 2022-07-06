#ifndef EA60714C_34D5_4F5D_BE86_F90D7D36C3BE
#define EA60714C_34D5_4F5D_BE86_F90D7D36C3BE

#include <SDL2/SDL.h>
#include <iostream>

class Window {
    private:
        SDL_Window* _Window;
    public:
        Window(const char* title, int width, int height);
        ~Window();
        bool IsOpen();
        SDL_Window* GetWindow();
};

#endif /* EA60714C_34D5_4F5D_BE86_F90D7D36C3BE */
