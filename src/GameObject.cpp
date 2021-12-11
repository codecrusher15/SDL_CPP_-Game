#include "../include/GameObject.hpp"
#include<iostream>
GameObject::GameObject(const char* texturePath,SDL_Renderer* renderer,const char* objectName,int direction)
{
	flip = direction; // if flip is 1 then source image get flipped during rendering 
	objectTexture = NULL;
	SDL_Texture* texture = NULL;
	objectTexture = IMG_LoadTexture(renderer,texturePath); //Loading texture
	if(objectTexture==NULL) std::cout <<"Failed to load " << objectName << std::endl; //Error if failed to load
	this->renderer = renderer;
}
void GameObject::Update(int x,int y,int width,int height) //x and y co-ordinates of texture
{
	srcRect.x=0;
	srcRect.y=0;
	srcRect.w=562;
	srcRect.h=519;

	dstRect.h=height;
	dstRect.w=width;
	dstRect.x=x;
	dstRect.y=y;
}

void GameObject::Render() //render function which render to screen when called inside the loop
{
	if(flip) SDL_RenderCopyEx(renderer,objectTexture,&srcRect,&dstRect,0,NULL,SDL_FLIP_HORIZONTAL);
	else SDL_RenderCopy(renderer,objectTexture,&srcRect,&dstRect);
}
int GameObject::getX()
{
	return x;
}
int GameObject::getY()
{
	return y;
}