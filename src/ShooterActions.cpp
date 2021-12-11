#include"../include/ShooterActions.hpp"
#include<iostream>
void ShooterActions::run(int direction)
{
	i=j;
	i = i%8;
	if(direction)
	{
		x-=4;
		player = runleftList[i];
	}
	else
	{
		x+=4;
		player = runList[i];
	}
	j+=0.1;
	if(x<0) x = 0;
	if(x>1600) x = 1600;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}

void ShooterActions::dead(int direction)
{
	i=j;
	i = i%10;
	if(direction)
	{
		player = deadleftList[i];
	}
	else
	{
		player = deadList[i];
	}
	j+=0.1;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}

void ShooterActions::shoot(int direction)
{
	i=j;
	i = i%4;
	if(direction)
	{
		player = shootleftList[i];
		bullet->leftFire(x,y+50);
	}
	else
	{
		player =shootList[i];
		bullet->rightFire(x+100,y+50);
	}
	j+=0.1;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}

void ShooterActions::idle(int direction)
{
	i=j;
	i = i%10;
	if(direction)
	{
		player = idleleftList[i];
	}
	else
	{
		player =idleList[i];
	}
	j+=0.1;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}
void ShooterActions::jump(int direction)
{
	i=j;
	i = i%10;
	if(direction)
	{
		x-=2;
		player = jumpleftList[i];
	}
	else
	{
		x+=2;
		player =jumpList[i];
	}
	if(y>500) y-=5;
	if(x<0) x = 0;
	if(x>1600) x = 1600;
	j+=0.1;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}
void ShooterActions::down(int direction)
{
	i=j;
	i = i%10;
	if(direction)
	{
		x-=2;
		player = jumpleftList[i];
	}
	else
	{
		x+=2;
		player =jumpList[i];
	}
	if(y<750) y+=5;
	if(x<0) x = 0;
	if(x>1600) x = 1600;
	j+=0.1;
	if(player)
	{
		player->Update(x,y,size,size);
		player->Render();
	}
	if(j>100) j =0;
	bullet->fired();
}
Bullet* ShooterActions::getBullet()
{
	return bullet;
}
ShooterActions::ShooterActions(SDL_Renderer* ren)
{
	renderer = ren;
	i=0;
	j=0;
	dir = 0;
	x=50;
	y=700;
	size=150;
	

	//loading run images
	runList.push_back(new Shooter("../res/shooterImages/r1.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r2.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r3.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r4.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r5.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r6.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r7.png",renderer,"Main Shooter",0));
	runList.push_back(new Shooter("../res/shooterImages/r8.png",renderer,"Main Shooter",0));
	
	runleftList.push_back(new Shooter("../res/shooterImages/r1.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r2.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r3.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r4.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r5.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r6.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r7.png",renderer,"Main Shooter",1));
	runleftList.push_back(new Shooter("../res/shooterImages/r8.png",renderer,"Main Shooter",1));

	//loading dead images
	deadList.push_back(new Shooter("../res/shooterImages/Dead (1).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (2).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (3).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (4).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (5).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (6).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (7).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (8).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (9).png",renderer,"Main Shooter",0));
	deadList.push_back(new Shooter("../res/shooterImages/Dead (10).png",renderer,"Main Shooter",0));

	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (1).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (2).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (3).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (4).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (5).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (6).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (7).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (8).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (9).png",renderer,"Main Shooter",1));
	deadleftList.push_back(new Shooter("../res/shooterImages/Dead (10).png",renderer,"Main Shooter",1));

	//loading shoot images
	shootList.push_back(new Shooter("../res/shooterImages/Shoot (1).png",renderer,"Main Shooter",0));
	shootList.push_back(new Shooter("../res/shooterImages/Shoot (2).png",renderer,"Main Shooter",0));
	shootList.push_back(new Shooter("../res/shooterImages/Shoot (3).png",renderer,"Main Shooter",0));
	shootList.push_back(new Shooter("../res/shooterImages/Shoot (4).png",renderer,"Main Shooter",0));

	shootleftList.push_back(new Shooter("../res/shooterImages/Shoot (1).png",renderer,"Main Shooter",1));
	shootleftList.push_back(new Shooter("../res/shooterImages/Shoot (2).png",renderer,"Main Shooter",1));
	shootleftList.push_back(new Shooter("../res/shooterImages/Shoot (3).png",renderer,"Main Shooter",1));
	shootleftList.push_back(new Shooter("../res/shooterImages/Shoot (4).png",renderer,"Main Shooter",1));

	//loading idle images
	idleList.push_back(new Shooter("../res/shooterImages/Idle (1).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (2).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (3).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (4).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (5).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (6).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (7).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (8).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (9).png",renderer,"Main Shooter",0));
	idleList.push_back(new Shooter("../res/shooterImages/Idle (10).png",renderer,"Main Shooter",0));

	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (1).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (2).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (3).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (4).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (5).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (6).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (7).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (8).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (9).png",renderer,"Main Shooter",1));
	idleleftList.push_back(new Shooter("../res/shooterImages/Idle (10).png",renderer,"Main Shooter",1));

	//loading jump images
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (1).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (2).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (3).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (4).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (5).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (6).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (7).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (8).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (9).png",renderer,"Main Shooter",0));
	jumpList.push_back(new Shooter("../res/shooterImages/Jump (10).png",renderer,"Main Shooter",0));

	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (1).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (2).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (3).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (4).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (5).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (6).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (7).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (8).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (9).png",renderer,"Main Shooter",1));
	jumpleftList.push_back(new Shooter("../res/shooterImages/Jump (10).png",renderer,"Main Shooter",1));

	bullet = new Bullet(renderer);
}