#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"GameObject.hpp"
class MainRenderer
{
private:
	SDL_Window* mainWindow;
	SDL_Renderer* renderer;
	GameObject* myObj;
public:
	MainRenderer(const char*,int,int);
	SDL_Texture* Background(const char*);
	void clear();
	void renderTexture(SDL_Texture*);
	void display(); 
	~MainRenderer();	
};