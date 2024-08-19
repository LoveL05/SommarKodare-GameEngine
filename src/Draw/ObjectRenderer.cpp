#include "ObjectRenderer.hpp"

ObjectRenderer::ObjectRenderer(SDL_Renderer *renderer): m_renderer(renderer) {
    m_textures = std::set<TextureL *>();
}

ObjectRenderer::~ObjectRenderer() {
    SDL_DestroyRenderer(m_renderer);

    for (auto texture : m_textures) {
        delete texture;
    }
}

void ObjectRenderer::renderAll() {
    for (auto texture : m_textures) {
        texture->draw();
    }
}

void ObjectRenderer::addTexture(TextureL *texture) {
    m_textures.insert(texture);
}

void ObjectRenderer::removeTexture(TextureL *texture) {
    m_textures.erase(texture);
}