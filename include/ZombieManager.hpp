#pragma once
#include"ZombieActions.hpp"
#include"ShooterActions.hpp"
#include<vector>
using std::vector; 
class ZombieManager
{
	private:
	vector<ZombieActions*> zombies;
	vector<int> isZombieDead;
	SDL_Renderer* renderer;
	vector<Bullet*> bullets;
	Bullet* bullet;
	ShooterActions* shooter;
	int delay;
	float velocity;
	public:
	ZombieManager(SDL_Renderer*,ShooterActions*);
	void AddZombies();
	void renderZombies();
	void killZombies();
};