#include "../include/GameObject.hpp"
#include<iostream>
GameObject::GameObject(const char* texturePath,SDL_Renderer* renderer,const char* objectName)
{
	objectTexture = NULL;
	SDL_Texture* texture = NULL;
	objectTexture = IMG_LoadTexture(renderer,texturePath);

	if(objectTexture==NULL) std::cout <<"Failed to load " << objectName << std::endl;
	this->renderer = renderer;
}

void GameObject::Update()
{
	srcRect.x=0;
	srcRect.y=0;
	srcRect.w=215;
	srcRect.h=183;

	dstRect.h=64;
	dstRect.w=64;
	dstRect.x=32;
	dstRect.y=32;
}

void GameObject::Render()
{
	SDL_RenderCopy(renderer,objectTexture,&srcRect,&dstRect);
}