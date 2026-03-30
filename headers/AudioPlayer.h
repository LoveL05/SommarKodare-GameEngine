#ifndef AUDIO_PLAYER_H_
#define AUDIO_PLAYER_H_

#include <SDL3/SDL.h>

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
        static void LoadSound(void *userdata, SDL_AudioStream *stream, int additional_data, int total_data);

        SDL_AudioStream *m_Device;
        SDL_AudioSpec m_AudioSpec, have;
        Uint8* m_waveStart;
        Uint32 m_waveLength;
};

#endif /* AUDIO_PLAYER_H_ */
