#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/MainRenderer.hpp"
#include"../include/Audio.hpp"
#include"../include/Button.hpp"
#include<time.h>
#include<stdio.h>

void delay(int n){
	int milli_seconds = 1000 * n;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

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
	MainRenderer* window = new MainRenderer("Zombie Shooter",1800,900);

	//Loading background
	SDL_Texture* initial = window->Background("../res/images/bgI.jpg");
	SDL_Texture* background = window->Background("../res/images/bg.jpg");

	Button* b_play = new Button(800,410,80,200, "../res/images/play.png");
	Mouse* m = new Mouse();
	SDL_StartTextInput();
	SDL_Rect* s = new SDL_Rect();
	s->x = 50;
	s->y = 50;
	s->h = 50;
	s->w = 60;
	bool Home_screen = true;
	bool Play_screen = false;
	bool start = true;

	//GameLoop
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT) running = false;
			window->passEvents(&event);
		}
		if(Home_screen){
			window->clear();
			SDL_PumpEvents();
			SDL_SetTextInputRect(s);
			window->renderTexture(initial);
			b_play->render_button(window);
			if(b_play->isClicked(m)){
				Home_screen = false;
				//delay(1);
				Play_screen = true;
			}
			//window->fontDisplay();
			window->display();
		}
		if(Play_screen){
				if(start){
					window->startGame();
					start = false;
				}
				// while (SDL_PollEvent(&event))
				// {
				// 	if(event.type == SDL_QUIT) running = false;
				// 	window->passEvents(&event);
				// }
				Audio *effect = new Audio();
				effect->Load("../res/Audio/Large-Zombie.wav");
				effect->play();	
				frameStart = SDL_GetTicks();
				audiotime = frameStart - b;
				if((audiotime >= 0) && (audiotime <= 1000))
				{
					b += 30000;
					effect->~Audio();
					effect->Load("../res/Audio/Large-Zombie.wav");
					effect->play();
				}
				window->clear();
				window->renderTexture(background);
				window->fontDisplay();
				window->display();
		}

		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelayTime > frameTime) SDL_Delay(frameDelayTime-frameTime);

	}
	

	window->~MainRenderer();
	SDL_Quit();
	return 0;
}