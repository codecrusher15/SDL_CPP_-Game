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
	zm = new ZombieManager(renderer,shooter->getBullet());
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
	zm->AddZombies();
}
void MainRenderer::display()
{
	SDL_RenderPresent(renderer);
}
void MainRenderer::passEvents(SDL_Event* event)
{
	kc->setEvent(event);
}
MainRenderer::~MainRenderer()
{
	SDL_RenderClear(renderer);
	SDL_DestroyWindow(mainWindow);
}