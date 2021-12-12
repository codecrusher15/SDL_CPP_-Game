#include"../include/ZombieManager.hpp"
#include<stdlib.h>
#include<iostream>
ZombieManager::ZombieManager(SDL_Renderer* ren,ShooterActions* shooter)
{
	renderer = ren;
	delay = 200;
	bullets = shooter->getBullet();
	this->shooter = shooter;
	this->velocity = 1;
}
void ZombieManager::AddZombies()
{
	bullets = shooter->getBullet();
	delay+=1;
	if(delay>200)
	{
		int arr[] = {500,600,700};
		int tmp = rand()%200+1800;
		int tmp1 = rand()%3;
		zombies.push_back(new ZombieActions(renderer,this->velocity,tmp,arr[tmp1]));
		isZombieDead.push_back(100);
		delay = this->velocity*50;
		if(delay>200) delay = 120;
		this->velocity+=0.1;
	}
	this->renderZombies();
	this->killZombies();
}
void ZombieManager::killZombies()
{
	int i = 0;
	while (i<zombies.size())
	{
		for (int k = 0; k < 5; k++)
		{
			bullet = bullets[k];
			if((zombies[i]->getX()<(bullet->getX()+15) && zombies[i]->getX()>(bullet->getX()-25)) && ((zombies[i]->getY()>bullet->getY()-200)&& (zombies[i]->getY()<bullet->getY())))
			{
				isZombieDead[i]--;
				if(isZombieDead[i]==99)
				{
					bullet->dead();
				}
			}
		}
		
		if(isZombieDead[i]<100 && isZombieDead[i]>60)
		{
			zombies[i]->dead();
			isZombieDead[i]--;
		}
		if(zombies[i]->getX()<0)
		{
			shooter->setDead();
		}
		if((zombies[i]->getX()<shooter->getX()+75 && zombies[i]->getX()+125>shooter->getX()) && (zombies[i]->getY()<shooter->getY() && shooter->getY()<zombies[i]->getY()+75))
		{
			shooter->setDead();
		}
		i++;
	}
	
}
void ZombieManager::renderZombies()
{
	for (int i = 0; i < zombies.size(); i++)
	{
		if(isZombieDead[i]>=100)zombies[i]->walk();
	}
	
}