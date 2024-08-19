#include "Texture.hpp"

TextureL::TextureL(WindowL *window, const char *path, SDL_Rect srcRect, SDL_Rect properties): m_window(window), m_srcRect(srcRect), m_properties(properties) {
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (surface == NULL) {
        printf("Unable to create surface: %s\n", SDL_GetError());
        delete surface;
        return;
    }

    m_texture = SDL_CreateTextureFromSurface(m_window->getNativeRenderer(), surface);

    SDL_FreeSurface(surface);
    if (m_texture == NULL) {
        printf("Unable to create texture: %s\n", SDL_GetError());
        return;
    }
}

TextureL::~TextureL() {
    SDL_DestroyTexture(m_texture);
    delete m_window;
}

void TextureL::draw() {
    SDL_RenderCopy(m_window->getNativeRenderer(), m_texture, &m_srcRect, &m_properties);
}
