#include <cstdio>

#include "Texture.h"

std::set<Texture2D*> Texture2D::Instances;

Texture2D::Texture2D(const char* path, SDL_Renderer* Renderer) {
    SDL_Surface* surface = SDL_LoadBMP(path);

    if (!surface) {
        printf("LoadBMP: %s\n", SDL_GetError());
        return;
    }

    _Texture = SDL_CreateTextureFromSurface(Renderer, surface);
    if (!_Texture) {
        printf("CreateTextureFromSurface: %s\n", SDL_GetError());
        return;
    }

    Instances.insert(this);

    SDL_DestroySurface(surface);
}

Texture2D::~Texture2D() {
    Instances.erase(this);
    SDL_DestroyTexture(_Texture);
}

SDL_Texture* Texture2D::GetTexture() {
    return _Texture;
}

std::set<Texture2D*> Texture2D::GetInstances() {
    return Instances;
}

SDL_FRect* Texture2D::Size() {
    return &_Size;
}

SDL_FRect* Texture2D::Position() {
    return &_Dest;
}

void Texture2D::SetSize(int x, int y) {
    _Size.w = x;
    _Size.h = y;
    _Dest.w = x;
    _Dest.h = y;
}

void Texture2D::SetPosition(int x, int y) {
    _Dest.x = x;
    _Dest.y = y;
}
