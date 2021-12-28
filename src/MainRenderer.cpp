#include"../include/MainRenderer.hpp"
#include<iostream>
using namespace std;
MainRenderer::MainRenderer(const char* title,int width,int height):mainWindow(NULL),renderer(NULL)
{
	mainWindow = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
	if(mainWindow == NULL) cout <<" Window failed to initialise. ERROR:" << SDL_GetError() << endl;
	renderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED);
	shooter = new ShooterActions(renderer);
	kc = new KeyboardController(renderer,shooter);
	zm = new ZombieManager(renderer,shooter);
	text_color = {255,255,255};
	fontsize = 30;
	font = TTF_OpenFont("../res/Montserrat/Montserrat-Regular.ttf", fontsize);
	if (font == NULL) {
	    std::cout << "Failed the load the font!\n";
	    std::cout << "SDL_TTF Error: " << TTF_GetError() << "\n";
	}
}

SDL_Texture*  MainRenderer::Background(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer,filePath);
	if(texture==NULL) cout <<"Failed to load Background" << endl;
	return texture;
}
void MainRenderer::clear()
{
	SDL_RenderClear(renderer);
}

void MainRenderer::renderTexture(SDL_Texture* tex)
{
	SDL_RenderCopy(renderer,tex,NULL,NULL);
	kc->ShooterControls();
	if(!kc->getShooterStatus())
		zm->AddZombies();
}
void MainRenderer::Render_texture(SDL_Texture* tex, int x, int y, int width, int height) 
{
    SDL_Rect* end = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    end->x = x;
    end->y = y;
    end->h = height;
    end->w = width;
    SDL_RenderCopy(this->renderer, tex, NULL, end);
	kc->ShooterControls();
}
void MainRenderer::display()
{
	SDL_RenderPresent(renderer);
}
void MainRenderer::passEvents(SDL_Event* event)
{
	kc->setEvent(event);
}

void MainRenderer::fontDisplay()
{
	int t = zm->getDeathCount();
	text = "Score : " + to_string(t);
	text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);
	Score_rect.x = 10;  //controls the rect's x coordinate 
	Score_rect.y = 10; // controls the rect's y coordinte
	Score_rect.w = 100; // controls the width of the rect
	Score_rect.h = 100; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture, nullptr, &Score_rect);
	SDL_FreeSurface(text_surface);
}

MainRenderer::~MainRenderer()
{
	SDL_RenderClear(renderer);
	SDL_DestroyWindow(mainWindow);
	delete kc;
	delete zm;
	kc = NULL;
	zm = NULL;
}

