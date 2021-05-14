#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<windows.h>
#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

using namespace std;

#undef main

const int WIDTH_BACKGROUND = 4800;
const int HEIGHT_BACKGROUND = 600;

const int WIDTH = 1200;
const int HEIGHT = 600;
const int BPP = 32;
const int NUM_THREATS=3;

static SDL_Surface* g_Image = NULL;
static SDL_Surface* g_Screen = NULL;
static SDL_Event g_Event;
static SDL_Surface* g_menu = NULL;

static Mix_Chunk* S_Amo[2] = { NULL,NULL };
static Mix_Chunk* S_Game_Over=NULL;
static Mix_Chunk* S_Colision = NULL;
static Mix_Chunk* S_Background = NULL;
static Mix_Music* S_B = NULL;

namespace SDL_commonFunction {
	
	SDL_Surface* Load_Image(string file_path);
	SDL_Rect Apply_Surface(SDL_Surface* str, SDL_Surface* des, int x, int y);
	void Apply_surface_Ex(SDL_Surface* str, SDL_Surface* des, SDL_Rect clip_, int x, int y);
	void Clean_Up();
	bool check_collision(const SDL_Rect& offset_a,const SDL_Rect& offset_b);
	int show_menu_(SDL_Surface* des, TTF_Font* font_);
	bool check_colision_menu(const int& x, const int& y,const SDL_Rect& rect);
}


#endif // !COMMON_FUNCTION_H_
