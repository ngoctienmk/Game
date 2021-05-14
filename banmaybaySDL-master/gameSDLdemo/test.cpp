#include<windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<iostream>
using namespace std;

#undef main

const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;

const int WIDTH = 1200;
const int HEIGHT = 600;
const int BPP = 32;
const int NUM_THREATS = 3;

static SDL_Surface* g_Image = NULL;
static SDL_Surface* g_Screen = NULL;
static SDL_Event g_Event;
static Mix_Chunk* S_background = NULL;
static Mix_Chunk* S_Colision = NULL;
static Mix_Chunk* no = NULL;

SDL_Surface* Load_Image(string file_path) {
	SDL_Surface* image = NULL;
	SDL_Surface* optimize = NULL;
	image = IMG_Load(file_path.c_str());
	if (image != NULL) {
		optimize = SDL_DisplayFormat(image);
		if (optimize != NULL)
		{
			Uint32 color_key = SDL_MapRGB(optimize->format, 0, 0xFF, 0xFF);
			SDL_SetColorKey(optimize, SDL_SRCCOLORKEY, color_key);
			SDL_FreeSurface(image);
		}

	}
	return optimize;
}
void Apply_Surface(SDL_Surface* str, SDL_Surface* des, int x, int y) {
	SDL_Rect offset, offset2;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(str, NULL, des, &offset);
}
void Clean_Up() {
	SDL_FreeSurface(g_Screen);
	SDL_FreeSurface(g_Image);
	SDL_Quit();
}
bool INIT() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	g_Screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		return false;
	}
	return true;
}
//void call() {
//	Mix_PlayChannel(-1, Sound, 0);
//}
int main() {
	int k = 0;
	int a = 0;
	int am;
	bool is_quit = false;
	if (INIT() == false) {
		return 1;
	}
	//
	S_Colision = Mix_LoadWAV("s_no.wav");
	S_background = Mix_LoadWAV("LaLung-Vu-4749614.wav");
	//
	g_Image = Load_Image("background.png");

	if (g_Image == NULL) {
		return 1;
	}
	Apply_Surface(g_Image, g_Screen, 0, 0);
	while (!is_quit) {
		
		while(SDL_PollEvent(&g_Event))
		{ 
			
			if (g_Event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}
			else if (g_Event.type == SDL_MOUSEBUTTONDOWN) {
				if (g_Event.button.button == SDL_BUTTON_LEFT) {
					Mix_PlayChannel(-1, no, 0);//am thanh bắn nhau
				}
				else if (g_Event.button.button == SDL_BUTTON_RIGHT) {
					Mix_PlayChannel(-1, S_Colision, 0);//am thanh va chạm
				}
			}
			else if (g_Event.type == SDL_KEYDOWN) {
				if(g_Event.key.keysym.sym==SDLK_UP){
					is_quit = true;
					break;
				}
				
			}
			
			k++;
			if (k == 10) {
				is_quit = true;
				break;
			}
			
		}
		SDL_Flip(g_Screen);
		a++;
	}

	cout << "So su kien bi bat:" << k << endl;
	cout << "So su kien thuc hien:" << a << endl;
	Clean_Up();
	SDL_Quit();
	return 0;
}
