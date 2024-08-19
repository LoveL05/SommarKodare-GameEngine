#ifndef DRAWHANDLER_HPP
#define DRAWHANDLER_HPP

#include <SDL2/SDL.h>
#include <set>
#include "Texture.hpp"

class ObjectRenderer {
private:
    SDL_Renderer *m_renderer;

    std::set<TextureL *> m_textures;
public:
    ObjectRenderer(SDL_Renderer *renderer);
    virtual ~ObjectRenderer();

    void addTexture(TextureL *texture);
    void removeTexture(TextureL *texture);

    void renderAll();
};

#endif