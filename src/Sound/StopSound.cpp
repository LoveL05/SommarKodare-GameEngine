#include <AudioPlayer.h>

void Sound::StopSound() {
    SDL_PauseAudioDevice(m_Device, 1);
}