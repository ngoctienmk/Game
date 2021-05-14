#include"common_function.h"
#include"base_Object.h"

base_Object::base_Object() {
	Rect_.x = 0;
	Rect_.y = 0;
	Image_ = NULL;
}
base_Object::~base_Object() {
	if (Image_ == NULL) {
		SDL_FreeSurface(Image_);
	}
}

bool  base_Object::Load_(string file_path) {
	Image_ = SDL_commonFunction::Load_Image(file_path.c_str());
	if (Image_ == NULL) {
		return false;
	}
	return true;
}
void base_Object::Show_(SDL_Surface* des) {
	if (Image_ != NULL) {

		Rect_ = SDL_commonFunction::Apply_Surface(Image_, des, Rect_.x, Rect_.y);
	}
	
}
void base_Object::Set_Rect_(const int& x, const int& y) {
	Rect_.x = x;
	Rect_.y = y;
}
