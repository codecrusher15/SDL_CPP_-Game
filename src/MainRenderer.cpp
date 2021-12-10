#include"../include/MainRenderer.hpp"
#include<iostream>
using namespace std;
MainRenderer::MainRenderer(const char* title,int width,int height):mainWindow(NULL),renderer(NULL)
{
	mainWindow = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
	if(mainWindow == NULL) cout <<" Window failed to initialise. ERROR:" << SDL_GetError() << endl;
	renderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED);
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
	bool init = true;
	GameObject obj = GameObject("../res/images/tmp.png",renderer,"Timepass");
	obj.Update();
	obj.Render();
}
void MainRenderer::display()
{
	SDL_RenderPresent(renderer);
}
MainRenderer::~MainRenderer()
{
	SDL_RenderClear(renderer);
	SDL_DestroyWindow(mainWindow);
}

