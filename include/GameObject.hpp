#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
class GameObject
{
	public:
	GameObject(const char* texture,SDL_Renderer*,const char*,int);
	void Update(int,int,int,int);
	void Render();
	int getX();
	int getY();

	private:
	int flip;
	int x,y;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect,dstRect;
	SDL_Renderer* renderer;
};