#pragma once
#include"Shooter.hpp"
#include"Bullet.hpp"
#include<vector>
using std::vector;
class ShooterActions
{
	private:
	Shooter* player;
	SDL_Renderer* renderer;
	Bullet* bullet;
	vector<const char*> vstr;
	vector<Shooter*> runList;
	vector<Shooter*> deadList;
	vector<Shooter*> shootList;
	vector<Shooter*> idleList;
	vector<Shooter*> runleftList;
	vector<Shooter*> deadleftList;
	vector<Shooter*> shootleftList;
	vector<Shooter*> idleleftList;
	vector<Shooter*> jumpList;
	vector<Shooter*> jumpleftList;
	int i,dir,x,y,size;
	float j;
	public:
	ShooterActions(SDL_Renderer*);
	void run(int);
	void dead(int );
	void shoot(int ); 
	void idle(int );
	void jump(int);
	void down(int);
	Bullet* getBullet();
};