#pragma once
#include"GameObject.hpp"
#include"Shooter.hpp"
#include<vector>
using std::vector;
class Bullet
{
	private:
	GameObject* leftBullet,*rightBullet;
	SDL_Renderer* renderer;
	bool isleftFired;
	bool isrightFired;
	int x,y,size;
	public:
	Bullet(SDL_Renderer*);
	void rightFire(int ,int);
	void leftFire(int,int);
	void fired();
	void dead();
	int getX();
	int getY();
	bool isRight();
	~Bullet();
};