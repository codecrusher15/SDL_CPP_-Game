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
	int dead_zombie = 0;
	bool isAlive = true;

	public:
	ZombieManager(SDL_Renderer*,ShooterActions*);
	void AddZombies();
	void renderZombies();
	void killZombies();
	int getDeathCount();
	bool Alive();
};