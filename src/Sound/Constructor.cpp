#include <AudioPlayer.h>

Sound::Sound(const char* path) {
    if (!SDL_LoadWAV(path, &have, &m_waveStart, &m_waveLength)) {
        SDL_Log("LoadWAV: %s\n", SDL_GetError());
        return;
    }
}