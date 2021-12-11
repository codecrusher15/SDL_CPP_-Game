#include"../include/ZombieActions.hpp"
ZombieActions::ZombieActions(SDL_Renderer* ren,float vel,int x,int y)
{
	renderer = ren;
	velocity = 0.1;
	xvel = vel;
	width = height = 200;
	i=0;
	this->x = x;
	this->y = y;
	currVel=0;
	//Loading walk images
	walkList.push_back(new Zombie("../res/zombie1/Attack (1).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (2).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (3).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (4).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (5).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (6).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (7).png",renderer,"Zombie1",1));
	walkList.push_back(new Zombie("../res/zombie1/Attack (8).png",renderer,"Zombie1",1));

	//Loading dying images
	deadList.push_back(new Zombie("../res/zombie1/Dead (1).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (2).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (3).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (4).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (5).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (6).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (7).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (8).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (9).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (10).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (11).png",renderer,"Zombie1",1));
	deadList.push_back(new Zombie("../res/zombie1/Dead (12).png",renderer,"Zombie1",1));
}

void ZombieActions::dead()
{
	i=currVel;
	i = i%12;
	zombie = deadList[i];
	currVel+=velocity;
	zombie->Update(x,y,width,height);
	zombie->Render();
	if(currVel>100) currVel =0;
	if(x<-150) x = 1800;
}

void ZombieActions::walk()
{
	i=currVel;
	i = i%8;
	zombie = walkList[i];
	x -= xvel;
	currVel+=velocity;
	zombie->Update(x,y,width,height);
	zombie->Render();
	if(currVel>100) currVel =0;
	if(x<-150) x = 1800;
}

int ZombieActions::getX()
{
	return x;
}

int ZombieActions::getY()
{
	return y;
}
