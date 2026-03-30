#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <SDL3/SDL.h>
#include <set>

class Texture2D {
        static std::set<Texture2D*> Instances;
        SDL_Texture* _Texture = nullptr;
        SDL_FRect _Size;
        SDL_FRect _Dest;
    public:
        SDL_FRect* Size();
        SDL_FRect* Position();
        void SetSize(int x, int y);
        void SetPosition(int x, int y);
        SDL_Texture* GetTexture();
        Texture2D(const char* path, SDL_Renderer* Renderer);
        ~Texture2D();
        static std::set<Texture2D*> GetInstances();
};

#endif /* TEXTURE_H_ */
