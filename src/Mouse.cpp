#include "../include/Mouse.hpp"

int Mouse::get_mouse_x(){
    SDL_GetMouseState(&x, &y);
    return this->x;
}

int Mouse::get_mouse_y(){
    SDL_GetMouseState(&x, &y);
    return this->y;
}

bool Mouse::isClicked(){
    Uint32 cursor = SDL_GetMouseState(&x, &y);
    if((cursor & SDL_BUTTON_LMASK) != 0) return true;
    return false;
}