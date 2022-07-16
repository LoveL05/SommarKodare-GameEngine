#include <Texture.h>
#include <iostream>

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

    SDL_FreeSurface(surface);
}