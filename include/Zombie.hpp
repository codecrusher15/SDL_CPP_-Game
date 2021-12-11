#pragma once
#include"GameObject.hpp"
class Zombie:public GameObject
{
	public:
	Zombie(const char*,SDL_Renderer*,const char*,int);
};