#include"../include/MainRenderer.hpp"
#include<iostream>
#include<fstream>
using namespace std;
//#include<time.h>
#include<stdio.h>

/*void delayX(int n){
	int milli_seconds = 1000 * n;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}*/

MainRenderer::MainRenderer(const char* title,int width,int height):mainWindow(NULL),renderer(NULL)
{
	GameOn = false;
	mainWindow = SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,width,height,SDL_WINDOW_SHOWN);
	if(mainWindow == NULL) cout <<" Window failed to initialise. ERROR:" << SDL_GetError() << endl;
	renderer = SDL_CreateRenderer(mainWindow,-1,SDL_RENDERER_ACCELERATED);
	// shooter = new ShooterActions(renderer);
	// kc = new KeyboardController(renderer,shooter);
	// zm = new ZombieManager(renderer,shooter);
	// text_color = {255,255,255};
	// fontsize = 30;
	// font = TTF_OpenFont("../res/Montserrat/Montserrat-Regular.ttf", fontsize);
	// if (font == NULL) {
	//     std::cout << "Failed the load the font!\n";
	//     std::cout << "SDL_TTF Error: " << TTF_GetError() << "\n";
	// }
}

void MainRenderer::startGame(){
	GameOn = true;
	shooter = new ShooterActions(renderer);
	kc = new KeyboardController(renderer,shooter);
	zm = new ZombieManager(renderer,shooter);
	text_color = {255,255,255};
	fontsize = 30;
	font = TTF_OpenFont("../res/Montserrat/Montserrat-Regular.ttf", fontsize);
	if (font == NULL) {
	    std::cout << "Failed the load the font!\n";
	    std::cout << "SDL_TTF Error: " << TTF_GetError() << "\n";
	}
}

SDL_Texture*  MainRenderer::Background(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer,filePath);
	if(texture==NULL) cout <<"Failed to load Background" << endl;
	return texture;
}
void MainRenderer::clear()
{
	SDL_RenderClear(renderer);
}

void MainRenderer::renderTexture(SDL_Texture* tex)
{
	SDL_RenderCopy(renderer,tex,NULL,NULL);
	if(GameOn){
		kc->ShooterControls();
		if(!kc->getShooterStatus())
		{
			zm->AddZombies();
		}
		else{
			this->isAlive = false;
			// cout << "main rend" << endl;
		}
	}
}
bool MainRenderer::Alive()
{
	return this->isAlive;
}
void MainRenderer::Render_texture(SDL_Texture* tex, int x, int y, int width, int height) 
{
    SDL_Rect* end = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    end->x = x;
    end->y = y;
    end->h = height;
    end->w = width;
    SDL_RenderCopy(this->renderer, tex, NULL, end);
	/*if(GameOn){
		kc->ShooterControls();
	}*/
}
void MainRenderer::display()
{
	SDL_RenderPresent(renderer);
}
void MainRenderer::passEvents(SDL_Event* event)
{
	if(GameOn){
		kc->setEvent(event);
	}
}

void MainRenderer::fontDisplay()
{
	this->t = zm->getDeathCount();
	text = "Score : " + to_string(t);
	text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);
	Score_rect.x = 10;  //controls the rect's x coordinate 
	Score_rect.y = 10; // controls the rect's y coordinte
	Score_rect.w = 100; // controls the width of the rect
	Score_rect.h = 100; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture, nullptr, &Score_rect);
	SDL_FreeSurface(text_surface);
}

void MainRenderer::DisplayLeaderboard(){
	int s1,s2,s3,s4,s5;
	ifstream myfile1 ("Topscores.txt");
	if (myfile1.is_open())
	{
		myfile1>>s1>>s2>>s3>>s4>>s5;
		myfile1.close();
	}
	text = "Leaderboard";
	text1 = "1)" + to_string(s1); 
	text2 = "2)" + to_string(s2);
	text3 = "3)" + to_string(s3);
	text4 = "4)" + to_string(s4);
	text5 = "5)" + to_string(s5);
	text_surface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	ftexture = SDL_CreateTextureFromSurface(renderer, text_surface);
	Score_rect.x = 500;  //controls the rect's x coordinate 
	Score_rect.y = 200; // controls the rect's y coordinte
	Score_rect.w = 800; // controls the width of the rect
	Score_rect.h = 100; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture, nullptr, &Score_rect);
	SDL_FreeSurface(text_surface);

	text_surface1 = TTF_RenderText_Solid(font, text1.c_str(), text_color);
	ftexture1 = SDL_CreateTextureFromSurface(renderer, text_surface1);
	Score_rect1.x = 300;  //controls the rect's x coordinate 
	Score_rect1.y = 300; // controls the rect's y coordinte
	Score_rect1.w = 150; // controls the width of the rect
	Score_rect1.h = 75; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture1, nullptr, &Score_rect1);
	SDL_FreeSurface(text_surface1);

	text_surface2 = TTF_RenderText_Solid(font, text2.c_str(), text_color);
	ftexture2 = SDL_CreateTextureFromSurface(renderer, text_surface2);
	Score_rect2.x = 300;  //controls the rect's x coordinate 
	Score_rect2.y = 400; // controls the rect's y coordinte
	Score_rect2.w = 150; // controls the width of the rect
	Score_rect2.h = 75; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture2, nullptr, &Score_rect2);
	SDL_FreeSurface(text_surface2);

	text_surface3 = TTF_RenderText_Solid(font, text3.c_str(), text_color);
	ftexture3 = SDL_CreateTextureFromSurface(renderer, text_surface3);
	Score_rect3.x = 300;  //controls the rect's x coordinate 
	Score_rect3.y = 500; // controls the rect's y coordinte
	Score_rect3.w = 150; // controls the width of the rect
	Score_rect3.h = 75; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture3, nullptr, &Score_rect3);
	SDL_FreeSurface(text_surface3);

	text_surface4 = TTF_RenderText_Solid(font, text4.c_str(), text_color);
	ftexture4 = SDL_CreateTextureFromSurface(renderer, text_surface4);
	Score_rect4.x = 300;  //controls the rect's x coordinate 
	Score_rect4.y = 600; // controls the rect's y coordinte
	Score_rect4.w = 150; // controls the width of the rect
	Score_rect4.h = 75; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture4, nullptr, &Score_rect4);
	SDL_FreeSurface(text_surface4);

	text_surface5 = TTF_RenderText_Solid(font, text5.c_str(), text_color);
	ftexture5 = SDL_CreateTextureFromSurface(renderer, text_surface5);
	Score_rect5.x = 300;  //controls the rect's x coordinate 
	Score_rect5.y = 700; // controls the rect's y coordinte
	Score_rect5.w = 150; // controls the width of the rect
	Score_rect5.h = 75; // controls the height of the rect
	SDL_RenderCopy(renderer, ftexture5, nullptr, &Score_rect5);
	SDL_FreeSurface(text_surface5);
}

int MainRenderer::get_score()
{
	return t;
}

void MainRenderer::KillAll()
{
	delete shooter;
	delete kc;
	delete zm;
	kc = NULL;
	zm = NULL;
	shooter = NULL;
}

MainRenderer::~MainRenderer()
{
	SDL_RenderClear(renderer);
	SDL_DestroyWindow(mainWindow);
	delete kc;
	delete zm;
	kc = NULL;
	zm = NULL;
}

