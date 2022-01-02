#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>
#include"../include/MainRenderer.hpp"
#include"../include/Audio.hpp"
#include"../include/Button.hpp"
//#include<time.h>
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
/*void delay(int n){
	int milli_seconds = 1000 * n;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}*/

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
	SDL_Texture* instructions = window->Background("../res/images/instr_bg.jpeg");
	SDL_Texture* Leaderboard = window->Background("../res/images/Leaderboard_bg.jpg");

	Button* b_play = new Button(90,80,80,200, "../res/images/play.png");
	Button* b_quit = new Button(1700,100,50,50, "../res/images/exit.jpg");
	Button* b_restart = new Button(1630,100,50,50, "../res/images/restart.jpg");
	Button* b_leaderboard = new Button(90,180,50,50, "../res/images/leaderboard.jpg");
	Button* b_instructions = new Button(160,180,50,50, "../res/images/instruction.jpg");
	Button* b_back = new Button(80,80,50,50, "../res/images/back.png");
	Mouse* m = new Mouse();
	SDL_StartTextInput();
	SDL_Rect* s = new SDL_Rect();
	s->x = 50;
	s->y = 50;
	s->h = 50;
	s->w = 60;
	// SDL_Rect* ins = new SDL_Rect();
	// ins->x = 200;
	// ins->y = 100;
	// ins->h = 500;
	// ins->w = 500;
	bool Home_screen = true;
	bool Play_screen = false;
	bool Instructions_screen = false;
	bool Leaderboard_screen = false;
	bool start = true;

	Audio *effect = new Audio();
	effect->Load("../res/Audio/Large-Zombie.wav");
	effect->play();
	//GameLoop
	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			//static int id=1;
			//std::cout<<"hello world" << id++ << std::endl;
			if(event.type == SDL_QUIT) running = false;
			window->passEvents(&event);
		}
		if(Home_screen){
			window->clear();
			//SDL_PumpEvents();
			SDL_SetTextInputRect(s);
			window->renderTexture(initial);
			b_play->render_button(window);
			b_leaderboard->render_button(window);
			b_instructions->render_button(window);
			if(b_play->isClicked(m)){
				Home_screen = false;
				//delay(1);
				Play_screen = true;
				start = true;
			}
			if(b_leaderboard->isClicked(m)){
				Leaderboard_screen = true;
				Home_screen = false;
			}
			if(b_instructions->isClicked(m)){
				Home_screen = false;
				Instructions_screen = true;
			}
			window->display();
		}
		if(Leaderboard_screen){
			window->clear();
			window->renderTexture(Leaderboard);
			b_back->render_button(window);
			if(b_back->isClicked(m)){
				Leaderboard_screen = false;
				Home_screen = true;
			}
			window->DisplayLeaderboard();
			window->display();
		}
		if(Instructions_screen){
			window->clear();
			window->renderTexture(instructions);
			b_back->render_button(window);
			if(b_back->isClicked(m)){
				Instructions_screen = false;
				Home_screen = true;
			}
			window->display();
		}
		if(Play_screen){
			window->clear();
			if(window->Alive())
			{
				window->renderTexture(background);

				if(start){
					window->startGame();
					start = false;
				}	

				frameStart = SDL_GetTicks();
				audiotime = frameStart - b;

				if((audiotime >= 0) && (audiotime <= 1000))
				{
					b += 30000;
					effect->~Audio();
					effect->Load("../res/Audio/Large-Zombie.wav");
					effect->play();
				}

				b_quit->render_button(window);
				if(b_quit->isClicked(m)){
					window->~MainRenderer();
					SDL_Quit();
					return 0;
				}

				b_restart->render_button(window);
				if(b_restart->isClicked(m)){
					window->startGame();
				}

				window->fontDisplay();
				window->display();
			}
			else
			{
				Play_screen = false;
				Home_screen = true;
				int score = window->get_score();
				//int s1,s2,s3,s4,s5;
				vector<int> numbers;
				ifstream myfile1 ("Topscores.txt");
				// if (myfile1.is_open())
				// {
				// 	myfile1>>s1>>s2>>s3>>s4>>s5;
				// 	myfile1.close();
				// }
				while (!myfile1.eof()) {
					int tmp;
					myfile1 >> tmp;
					numbers.push_back(tmp);
				}
				myfile1.close();
				if(score >= numbers[0]){
					numbers[4] = numbers[3];
					numbers[3] = numbers[2];
					numbers[2] = numbers[1];
					numbers[1] = numbers[0];
					numbers[0] = score;

				}
				else if(score >= numbers[1]) 
				{
					numbers[4] = numbers[3];
					numbers[3] = numbers[2];
					numbers[2] = numbers[1];
					numbers[1] = score;
				}
				else if(score >= numbers[2]) 
				{
					numbers[4] = numbers[3];
					numbers[3] = numbers[2];
					numbers[2] = score;
				}
				else if(score >= numbers[3]) 
				{
					numbers[4] = numbers[3];
					numbers[3] = score;
				}
				else if(score >= numbers[4]) 
				{
					numbers[4] = score;
				}
				ofstream myfile ("Topscores.txt");
				if (myfile.is_open())
				{
					myfile<<numbers[0]<< " " <<numbers[1]<< " " <<numbers[2]<< " " <<numbers[3]<< " " <<numbers[4];
					myfile.close();
				}
				//window->KillAll();
				//cout << "shooter dead" << endl;
			}
		}

		frameTime = SDL_GetTicks() - frameStart;
		if(frameDelayTime > frameTime) SDL_Delay(frameDelayTime-frameTime);

	}
	

	window->~MainRenderer();
	SDL_Quit();
	return 0;
}