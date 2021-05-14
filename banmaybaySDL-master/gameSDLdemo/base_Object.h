#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include"common_function.h"

class base_Object {
protected:
	SDL_Rect Rect_;
	SDL_Surface* Image_;
public:
	base_Object();
	~base_Object();
	bool Load_(string file_path);
	void Show_(SDL_Surface* des);
	void Set_Rect_(const int& x, const int& y);
	SDL_Rect get_rect() { return Rect_; }
	SDL_Surface* get_surface() { return Image_; }
	

};


#endif // !BASE_OBJECT_H_
