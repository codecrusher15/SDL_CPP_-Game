#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/MainRenderer.hpp"
using namespace std;
int main()
{
	if(SDL_Init(SDL_INIT_VIDEO) >0)
		cout << "SDL initialisation failed. ERROR:" << SDL_GetError() << endl;
	
	if(!(IMG_Init(IMG_INIT_PNG)))
		cout << "Image initialisation failed. ERROR:" << SDL_GetError() << endl;
	MainRenderer window("Fort Lords",1800,900);
	SDL_Texture* background = window.Background("../res/images/bg.jpg");
	bool running = true;


	//GameLoop
	SDL_Event event;
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) running = false;
		}
		window.clear();
		window.renderTexture(background);
		window.display();
	}
	

	window.~MainRenderer();
	SDL_Quit();
	return 0;
}