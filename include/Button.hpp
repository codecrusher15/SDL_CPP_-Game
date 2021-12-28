#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "MainRenderer.hpp"
#include "Mouse.hpp"

class Button{
    private:
    int x;
    int y;
    int height;
    int width;
    const char* image_path;

    public:
    Button(int x, int y, int height, int width, const char* image_path);
    void render_button(MainRenderer* w);
    bool isOnButton(Mouse* m);
    bool isClicked(Mouse* m);
};