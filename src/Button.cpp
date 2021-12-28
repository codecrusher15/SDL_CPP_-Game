#include "../include/Button.hpp"

Button::Button(int x, int y, int height, int width, const char* image_path){
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    this->image_path = image_path;
}

void Button::render_button(MainRenderer* w){
    SDL_Texture* texture = w->Background(this->image_path);
    w->Render_texture(texture, this->x, this->y, this->width, this->height);
}

bool Button::isOnButton(Mouse* m){
    int m_x = m->get_mouse_x();
    int m_y = m->get_mouse_y();
    if((m_x > this->x) && (m_x < this->x + this->width) && (m_y > this->y) && (m_y < this->y + this->height)){
        return true;
    }
    return false;
}

bool Button::isClicked(Mouse* m){
    if(this->isOnButton(m) && m->isClicked()){
        return true;
    }
    return false;
}