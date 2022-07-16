#include <AudioPlayer.h>

void Sound::PlaySound() {
    int status = SDL_QueueAudio(m_Device, m_waveStart, m_waveLength);
    SDL_PauseAudioDevice(m_Device, 0);
}