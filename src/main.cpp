#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/MainRenderer.hpp"
#include"../include/Audio.hpp"

int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "SDL initialisation failed. ERROR:" << SDL_GetError() << std::endl;
	
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "Image initialisation failed. ERROR:" << SDL_GetError() << std::endl;

	if(SDL_Init(SDL_INIT_AUDIO) < 0)
		std::cout << "SDL Audio initialisation failed. ERROR:" << SDL_GetError() << std::endl;

	if(TTF_Init() < 0)
		std::cout << "TTF initialisation failed. ERROR:" <<TTF_GetError() << std::endl;


	bool running = true;
	//FPS
	const int FPS = 60;
	const int frameDelayTime = 1000/FPS;
	Uint32  frameStart;
	int frameTime;
	Uint32 audiotime, b = 30000;
	
	//Event
	SDL_Event event;

	//Window creation
	MainRenderer window("Zombie Shooter",1800,900);

	//Loading background
	SDL_Texture* background = window.Background("../res/images/bg.jpg");

	Audio *effect = new Audio();
	effect->Load("../res/Audio/Large-Zombie.wav");
	effect->play();	
	//GameLoop
	while (running)
	{
		frameStart = SDL_GetTicks();
		audiotime = frameStart - b;
		if((audiotime >= 0) && (audiotime <= 1000))
		{
			b += 30000;
			effect->~Audio();
			effect->Load("../res/Audio/Large-Zombie.wav");
			effect->play();
		}
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) running = false;
			window.passEvents(&event);
		}
		window.clear();
		window.renderTexture(background);
		window.fontDisplay();
		window.display();

		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelayTime > frameTime) SDL_Delay(frameDelayTime-frameTime);

	}
	

	window.~MainRenderer();
	SDL_Quit();
	return 0;
}