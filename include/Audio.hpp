#pragma once
#include<SDL2/SDL.h>

class Audio
{
    private:
        SDL_AudioSpec spec;
        Uint32 length;
        Uint8 *buffer;
        SDL_AudioDeviceID deviceId;

    public:
        Audio();
        ~Audio();
        void Load(const char *file);
        void play();
};