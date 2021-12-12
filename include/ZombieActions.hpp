#pragma once
#include"Zombie.hpp"
#include<vector>
using std::vector;
class ZombieActions
{
	private:
	Zombie* zombie;
	vector<Zombie*> walkList;
	vector<Zombie*> deadList;
	SDL_Renderer* renderer;
	int i,x,y,width,height;
	float velocity,currVel,xvel;
	public:
	ZombieActions(SDL_Renderer*,float vel,int x,int y);
	void walk();
	void dead();
	int getX();
	int getY();
	~ZombieActions();
};