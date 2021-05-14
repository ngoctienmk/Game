#include"Explosion_Object.h"

Ex_Object::Ex_Object() {
	frame = 0;
}
Ex_Object ::~Ex_Object(){

}

void Ex_Object::set_clip(){
	Ex_clip[0].x = 0;
	Ex_clip[0].y = 0;
	Ex_clip[0].w = EX_WIDTH;
	Ex_clip[0].h = EX_HEIGHT;

	Ex_clip[1].x = EX_WIDTH;
	Ex_clip[1].y = 0;
	Ex_clip[1].w = EX_WIDTH;
	Ex_clip[1].h = EX_HEIGHT;

	Ex_clip[2].x = EX_WIDTH*2;
	Ex_clip[2].y = 0;
	Ex_clip[2].w = EX_WIDTH;
	Ex_clip[2].h = EX_HEIGHT;

	Ex_clip[3].x = EX_WIDTH*3;
	Ex_clip[3].y = 0;
	Ex_clip[3].w = EX_WIDTH;
	Ex_clip[3].h = EX_HEIGHT;
}

void Ex_Object::show_Ex( SDL_Surface* des, int x, int y){
	if (frame >= 4) {
		frame = 0;
	}
	SDL_commonFunction::Apply_surface_Ex(Image_, des, Ex_clip[frame], x, y);
}