#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include"base_Object.h"
#include<string>
#include<SDL_ttf.h>

class text_object_ :public base_Object {
private:
	string text_name;
	SDL_Color color_text;
public:
	enum type_text
	{
		RED_TEXT = 0,
		WHILE_TEXT = 1,
		BLACK_TEXT=2
	};
	text_object_();
	~text_object_();
	void set_text_name(const string &name);

	void set_color_text(const int& type);
	void render_text(TTF_Font* font, SDL_Surface* des);


};

#endif // !TEXT_OBJECT_H_
