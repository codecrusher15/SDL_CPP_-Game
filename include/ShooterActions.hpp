#pragma once
#include"Shooter.hpp"
#include"Bullet.hpp"
#include "Audio.hpp"
#include<vector>
using std::vector;
class ShooterActions
{
	private:
	Shooter* player;
	SDL_Renderer* renderer;
	vector<Bullet*> bullets;
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
	int i,dir,x,y,size,bulletDelay;
	bool isDead;
	float j;
	Audio *effect;
	public:
	ShooterActions(SDL_Renderer*);
	void run(int);
	void dead(int );
	void shoot(int ); 
	void idle(int );
	void jump(int);
	void down(int);
	int getX();
	int getY();
	void setDead();
	bool getShooterStatus();
	vector<Bullet*> getBullet();
	~ShooterActions();
};