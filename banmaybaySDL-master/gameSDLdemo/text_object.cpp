#include"text_object.h"

text_object_::text_object_() {
	Rect_.x = 500;
	Rect_.y = 10;

}
text_object_ ::~text_object_() {
	//to do
}
void text_object_::set_text_name(const string& name) {
	text_name = name;
}

void text_object_::set_color_text(const int& type) {
	if (type == RED_TEXT) {
		color_text = { 255,0,0 };
	}
	else if (type == WHILE_TEXT) {
		color_text = { 255,255,255 };
	}
	else
	{
		color_text = { 0,0,0 };
	}
}
void text_object_::render_text(TTF_Font*font,SDL_Surface*des) {
	Image_ = TTF_RenderText_Solid(font, text_name.c_str(), color_text);
	Show_(des);
}