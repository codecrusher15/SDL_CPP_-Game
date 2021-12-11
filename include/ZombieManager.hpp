#pragma once
#include"ZombieActions.hpp"
#include"Bullet.hpp"
#include<vector>
using std::vector; 
class ZombieManager
{
	private:
	vector<ZombieActions*> zombies;
	vector<int> isZombieDead;
	SDL_Renderer* renderer;
	Bullet* bullet;
	int delay;
	float velocity;
	public:
	ZombieManager(SDL_Renderer*,Bullet*);
	void AddZombies();
	void renderZombies();
	void killZombies();
};