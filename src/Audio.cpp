#include "../include/Audio.hpp"

Audio::Audio()
{
    ;
}

void Audio::Load(const char *filename)
{
    SDL_LoadWAV(filename, &spec, &buffer, &length);
    deviceId = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
}

void Audio::play()
{
    SDL_QueueAudio(deviceId, buffer, length);
    SDL_PauseAudioDevice(deviceId, 0);
}

Audio::~Audio()
{
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(buffer);
}