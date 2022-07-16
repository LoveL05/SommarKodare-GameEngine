#include <AudioPlayer.h>

Sound::~Sound() {
    SDL_FreeWAV(m_waveStart);
    SDL_CloseAudioDevice(m_Device);
}