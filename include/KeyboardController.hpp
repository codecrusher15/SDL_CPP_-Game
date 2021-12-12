#pragma 
#include"ShooterActions.hpp"
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
class KeyboardController
{
	private:
	ShooterActions* shooter;
	SDL_Event* event;
	int currAction;
	int direction;
	public:
	KeyboardController(SDL_Renderer* render,ShooterActions*);
	void ShooterControls();
	void setEvent(SDL_Event* evn);
	bool getShooterStatus();
};