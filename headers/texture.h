#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL3/SDL.h>
#include <set>

class Texture2D {
        static std::set<Texture2D*> Instances;
        SDL_Texture* m_texture = nullptr;
        SDL_FRect m_size;
        SDL_FRect m_dest;
    public:
        SDL_FRect* getSize();
        SDL_FRect* getPosition();

        void setSize(int x, int y);
        void setPosition(int x, int y);

        SDL_Texture* getTexture();
        
        Texture2D(const char* path, SDL_Renderer* Renderer);
        ~Texture2D();

        static std::set<Texture2D*> getInstances();
};

#endif /* TEXTURE_H_ */
