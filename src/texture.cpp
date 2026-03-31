#include <cstdio>

#include "texture.h"

std::set<Texture2D*> Texture2D::Instances;

Texture2D::Texture2D(const char* path, SDL_Renderer* Renderer) {
    SDL_Surface* surface = SDL_LoadBMP(path);

    if (!surface) {
        printf("LoadBMP: %s\n", SDL_GetError());
        return;
    }

    m_texture = SDL_CreateTextureFromSurface(Renderer, surface);
    if (!m_texture) {
        printf("CreateTextureFromSurface: %s\n", SDL_GetError());
        return;
    }

    Instances.insert(this);

    SDL_DestroySurface(surface);
}

Texture2D::~Texture2D() {
    Instances.erase(this);
    SDL_DestroyTexture(m_texture);
}

SDL_Texture* Texture2D::getTexture() {
    return m_texture;
}

std::set<Texture2D*> Texture2D::getInstances() {
    return Instances;
}

SDL_FRect* Texture2D::getSize() {
    return &m_size;
}

SDL_FRect* Texture2D::getPosition() {
    return &m_dest;
}

void Texture2D::setSize(int x, int y) {
    m_size.w = x;
    m_size.h = y;
    m_dest.w = x;
    m_dest.h = y;
}

void Texture2D::setPosition(int x, int y) {
    m_dest.x = x;
    m_dest.y = y;
}
