#ifndef EXPLOSION_OBJECT_H_
#define EXPLOSION_OBJECT_H_

#include"base_Object.h"

const int EX_WIDTH = 165;
const int EX_HEIGHT = 165;

class Ex_Object :public base_Object {
private:
	int frame;
	SDL_Rect Ex_clip[4];
public:
	Ex_Object();
	~Ex_Object();

	void set_frame(const int& fr) { frame = fr; }
	void set_clip();

	void show_Ex(SDL_Surface*des,int x,int y);
};

#endif // !EXPLOSION_OBJECT_H_

