#include "AudioPlayer.h"

void Sound::LoadSound(void *userdata, SDL_AudioStream *stream, int additional_data, int total_data) {
    Sound *sound = (Sound *) userdata;
    SDL_PutAudioStreamData(stream, sound->m_waveStart, sound->m_waveLength);
}

Sound::Sound(const char* path) : m_path(path) {
    if (!SDL_LoadWAV(path, &m_AudioSpec, &m_waveStart, &m_waveLength)) {
        SDL_Log("LoadWAV: %s\n", SDL_GetError());
        return;
    }
}

Sound::~Sound() {
    SDL_free(m_waveStart);
    SDL_DestroyAudioStream(m_Device);
}

void Sound::PlaySound() {
    if (!SDL_ResumeAudioStreamDevice(m_Device)) {
        SDL_Log("SDL_ResumeAudioStreamDevice: %s\n", SDL_GetError());
        return;
    }
}

void Sound::SetupDevice() {
    m_Device = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &m_AudioSpec, LoadSound, this);
    if (!m_Device) {
        SDL_Log("OpenAudioDevice: %s\n", SDL_GetError());
        return;
    }
}

void Sound::StopSound() {
    SDL_PauseAudioStreamDevice(m_Device);
}
