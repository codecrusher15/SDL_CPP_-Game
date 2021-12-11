#include"../include/KeyboardController.hpp"
#include<iostream>
KeyboardController::KeyboardController(SDL_Renderer* render,ShooterActions* shooter)
{
	this->shooter = shooter;
	currAction = 0;
	direction = 0;
}
void KeyboardController::setEvent(SDL_Event* evn)
{
	this->event = evn;
	if(event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
		case SDLK_d:
			currAction=1;
			direction=0;
			break;
		case SDLK_s:
			currAction=2;
			break;
		case SDLK_a:
			currAction=3;
			direction=1;
			break;
		case SDLK_w:
			currAction=4;
			break;
		case SDLK_SPACE:
			currAction=5;
			break;
		default:
			break;
		}
	}
	if(event->type == SDL_KEYUP)
	{
		currAction = 0;
	}
}
void KeyboardController::ShooterControls()
{
	switch (currAction)
	{
	case 1:
		shooter->run(direction);
		break;
	case 2:
		shooter->down(direction);
		break;
	case 3:
		shooter->run(direction);
		break;
	case 4:
		shooter->jump(direction);
		break;
	case 5:
		shooter->shoot(direction);
		break;
	default:
		shooter->idle(direction);
		break;
	}
}