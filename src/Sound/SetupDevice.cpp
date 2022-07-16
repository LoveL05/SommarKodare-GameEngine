#include <AudioPlayer.h>
#include <iostream>

void Sound::SetupDevice() {
    m_AudioSpec.freq = 48000;
    m_AudioSpec.format = AUDIO_F32;
    m_AudioSpec.channels = 2;
    m_AudioSpec.samples = 4096;

    m_Device = SDL_OpenAudioDevice(NULL, 0, &m_AudioSpec, &have, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (!m_Device) {
        SDL_Log("OpenAudioDevice: %s\n", SDL_GetError());
        return;
    }
}