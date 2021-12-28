#pragma once

#include<inttypes.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <string>

using namespace std;

class Mouse{
    private:
    int x;
    int y;

    public:
    int get_mouse_x();
    int get_mouse_y();
    bool isClicked();
};