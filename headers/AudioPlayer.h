#ifndef DC24CBF4_F2FD_4FBE_9769_DC08A85640B5
#define DC24CBF4_F2FD_4FBE_9769_DC08A85640B5

#include <SDL2/SDL.h>

class ISound {
    public:
        virtual ~ISound() {};
        virtual void PlaySound() = 0;
        virtual void StopSound() = 0;
};

class Sound : ISound {
    public:
        Sound(const char* path);
        ~Sound();

        void PlaySound();
        void StopSound();
        void SetupDevice();
    private:
        SDL_AudioDeviceID m_Device;
        SDL_AudioSpec m_AudioSpec, have;
        Uint8* m_waveStart;
        Uint32 m_waveLength;
};

#endif /* DC24CBF4_F2FD_4FBE_9769_DC08A85640B5 */
