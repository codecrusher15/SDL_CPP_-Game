#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include"KeyboardController.hpp"
#include"ZombieManager.hpp"
#include"ShooterActions.hpp"
class MainRenderer
{
private:
	SDL_Window* mainWindow;
	SDL_Renderer* renderer;
	KeyboardController* kc;
	ZombieManager* zm;
	ShooterActions* shooter;
public:
	MainRenderer(const char*,int,int);
	SDL_Texture* Background(const char*);
	void clear();
	void renderTexture(SDL_Texture*);
	void display();
	void passEvents(SDL_Event*);
	~MainRenderer();	
};