#include <Texture.h>

SDL_Texture* Texture2D::GetTexture() {
    return _Texture;
}

std::set<Texture2D*> Texture2D::GetInstances() {
    return Instances;
}

SDL_Rect* Texture2D::Size() {
    return &_Size;
}

SDL_Rect* Texture2D::Position() {
    return &_Dest;
}