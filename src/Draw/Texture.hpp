#ifndef DRAW_HPP
#define DRAW_HPP

#include "../Window/WindowL.hpp"

class TextureL {
private:
    WindowL *m_window;

    SDL_Texture *m_texture;
    SDL_Rect m_properties;
    SDL_Rect m_srcRect;
public:
    TextureL(WindowL *window, const char *path, SDL_Rect srcRect, SDL_Rect properties);
    virtual ~TextureL();

    void draw();
};

#endif // DRAW_HPP