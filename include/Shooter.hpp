#pragma once
#include"GameObject.hpp"
class Shooter:public GameObject
{
	public:
	Shooter(const char* texturePath,SDL_Renderer* renderer,const char* objectName,int);
};