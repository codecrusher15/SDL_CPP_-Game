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
	int t;
	TTF_Font* font;
	SDL_Color text_color;
	std::string text = "0";
	std::string text1 = "0";
	std::string text2 = "0";
	std::string text3 = "0";
	std::string text4 = "0";
	std::string text5 = "0";
	SDL_Surface *text_surface, *text_surface1, *text_surface2, *text_surface3, *text_surface4, *text_surface5;
	SDL_Texture* ftexture = nullptr;
	SDL_Texture* ftexture1 = nullptr;
	SDL_Texture* ftexture2 = nullptr;
	SDL_Texture* ftexture3 = nullptr;
	SDL_Texture* ftexture4 = nullptr;
	SDL_Texture* ftexture5 = nullptr;
	SDL_Rect Score_rect, Score_rect1, Score_rect2, Score_rect3, Score_rect4, Score_rect5;
	bool GameOn;
	bool isAlive = true;
public:
	MainRenderer(const char*,int,int);
	SDL_Texture* Background(const char*);
	void clear();
	void renderTexture(SDL_Texture*);
	void Render_texture(SDL_Texture* tex, int x, int y, int width, int height);
	void display();
	void passEvents(SDL_Event*);
	void fontDisplay();
	void KillAll();
	int get_score();
	void DisplayLeaderboard();
	void startGame();
	bool Alive();
	~MainRenderer();	
};