#include"../include/Bullet.hpp"
Bullet::Bullet(SDL_Renderer* renderer)
{
	rightBullet = new GameObject("../res/images/Bullet_000.png",renderer,"bullet",0);
	leftBullet = new GameObject("../res/images/Bullet_000.png",renderer,"bullet",1);
	isleftFired = false;
	isrightFired = false;
	size = 50;
}

void Bullet::rightFire(int x,int y)
{
	if(!(isleftFired) && !(isrightFired))
	{
		isrightFired = true;
		this->x = x;
		this->y = y;
	}
}

void Bullet::leftFire(int x,int y)
{
	if(!(isleftFired) && !(isrightFired))
	{
		isleftFired = true;
		this->x = x;
		this->y = y;
	}
}

void Bullet::fired()
{
	if(isleftFired)
	{
		leftBullet->Update(x,y,size,size);
		leftBullet->Render();
		x-=10;
		if(x<0) isleftFired = false;
	}
	else if(isrightFired)
	{
		rightBullet->Update(x,y,size,size);
		rightBullet->Render();
		x+=10;
		if(x>1800) isrightFired = false;
	}
}

void Bullet::dead()
{
	isrightFired = false;
	isleftFired = false;
	x = -10;
	y = -10;
}

int Bullet::getX()
{
	return x;
}
int Bullet::getY()
{
	return y;
}
bool Bullet::isRight()
{
	if(isrightFired) return true;
	else return false;
}

Bullet::~Bullet()
{
	delete rightBullet;
	delete leftBullet;
	rightBullet = NULL;
	leftBullet = NULL;
}