#pragma once
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
class GameObject
{
	public:
	GameObject(const char* texture,SDL_Renderer*,const char*);
	void Update();
	void Render();

	private:
	int x,y;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect,dstRect;
	SDL_Renderer* renderer;
};