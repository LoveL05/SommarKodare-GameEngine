#include <Texture.h>

Texture2D::~Texture2D() {
    Instances.erase(this);
    SDL_DestroyTexture(_Texture);
}