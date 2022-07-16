#ifndef F71231D2_72C2_43F4_AD8F_02B0AA995CCE
#define F71231D2_72C2_43F4_AD8F_02B0AA995CCE
#ifndef C5772FD0_A916_4138_A463_823A3D065162
#define C5772FD0_A916_4138_A463_823A3D065162

#include <SDL2/SDL.h>
#include <set>

class Texture2D {
        static std::set<Texture2D*> Instances;
        SDL_Texture* _Texture = nullptr;
        SDL_Rect _Size;
        SDL_Rect _Dest;
    public:
        SDL_Rect* Size();
        SDL_Rect* Position();
        void SetSize(int x, int y);
        void SetPosition(int x, int y);
        SDL_Texture* GetTexture();
        Texture2D(const char* path, SDL_Renderer* Renderer);
        ~Texture2D();
        static std::set<Texture2D*> GetInstances();
};

#endif /* C5772FD0_A916_4138_A463_823A3D065162 */


#endif /* F71231D2_72C2_43F4_AD8F_02B0AA995CCE */
