#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/MainRenderer.hpp"
int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) >0)
		std::cout << "SDL initialisation failed. ERROR:" << SDL_GetError() << std::endl;
	
	if(!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "Image initialisation failed. ERROR:" << SDL_GetError() << std::endl;



	bool running = true;
	//FPS
	const int FPS = 60;
	const int frameDelayTime = 1000/FPS;
	Uint32  frameStart;
	int frameTime;
	
	//Event
	SDL_Event event;

	//Window creation
	MainRenderer window("Zombie Shooter",1800,900);

	//Loading background
	SDL_Texture* background = window.Background("../res/images/bg.jpg");

	
	//GameLoop
	while (running)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) running = false;
			window.passEvents(&event);
		}
		window.clear();
		window.renderTexture(background);
		window.display();

		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelayTime > frameTime) SDL_Delay(frameDelayTime-frameTime);

	}
	

	window.~MainRenderer();
	SDL_Quit();
	return 0;
}