#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<string>
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
	int fontsize;
	TTF_Font* font;
	SDL_Color text_color;
	std::string text = "0";
	SDL_Surface *text_surface;
	SDL_Texture* ftexture = nullptr;
	SDL_Rect Score_rect;
	bool GameOn;
public:
	MainRenderer(const char*,int,int);
	SDL_Texture* Background(const char*);
	void clear();
	void renderTexture(SDL_Texture*);
	void Render_texture(SDL_Texture* tex, int x, int y, int width, int height);
	void display();
	void passEvents(SDL_Event*);
	void fontDisplay();
	void startGame();
	~MainRenderer();	
};