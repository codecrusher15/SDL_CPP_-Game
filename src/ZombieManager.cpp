#include"../include/ZombieManager.hpp"
#include<stdlib.h>
ZombieManager::ZombieManager(SDL_Renderer* ren,Bullet* bul)
{
	renderer = ren;
	delay = 200;
	bullet = bul;
	this->velocity = 1;
}
void ZombieManager::AddZombies()
{
	delay+=1;
	if(delay>250)
	{
		int arr[] = {750,700,800};
		int tmp = rand()%200+1800;
		int tmp1 = rand()%3;
		zombies.push_back(new ZombieActions(renderer,this->velocity,tmp,arr[tmp1]));
		isZombieDead.push_back(100);
		delay = this->velocity*20;
		this->velocity+=0.05;
	}
	this->renderZombies();
	this->killZombies();
}
void ZombieManager::killZombies()
{
	int i = 0;
	while (i<zombies.size())
	{
		if(zombies[i]->getX()<(bullet->getX()+15) && zombies[i]->getX()>(bullet->getX()-25))
		{
			isZombieDead[i]--;
			if(isZombieDead[i]==99)
			{
				bullet->dead();
			}
		}
		if(isZombieDead[i]<100 && isZombieDead[i]>60)
		{
			zombies[i]->dead();
			isZombieDead[i]--;
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