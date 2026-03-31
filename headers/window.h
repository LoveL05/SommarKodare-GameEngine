#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL3/SDL.h>

class Window {
public: 
    SDL_Window* getWindow();
    SDL_Surface* getSurface();
    SDL_Renderer* getRenderer();
    
    Window(const char* title, int width, int height);
    ~Window();
    
private:
    SDL_Window* m_window = nullptr;
    SDL_Surface* m_surface = nullptr;
    SDL_Renderer* m_renderer = nullptr;
};

#endif /* WINDOW_H_ */
