
#include"common_function.h"
#include"text_object.h"

bool SDL_commonFunction::check_colision_menu(const int& x, const int& y, const SDL_Rect& rect) {
	if (x >= rect.x && x <= rect.x + rect.w && y > rect.y && y < rect.y + rect.h) {
		return true;
	}
	return false;
}
int SDL_commonFunction:: show_menu_(SDL_Surface* des, TTF_Font*font_) {
	g_menu = SDL_commonFunction::Load_Image("menugame2.png");
	if (g_menu == NULL) {
		return 1;
	}
	const int kItemmenu = 2;
	text_object_ text_menu[kItemmenu];

	text_menu[0].set_text_name("Play Game");
	text_menu[0].set_color_text(text_object_::BLACK_TEXT);
	text_menu[0].Set_Rect_(200, 300);

	text_menu[1].set_text_name("Quit Game");
	text_menu[1].set_color_text(text_object_::BLACK_TEXT);
	text_menu[1].Set_Rect_(200, 400);
	SDL_Event m_event;
	int xc,yc;
	while (true)
	{
		SDL_commonFunction::Apply_Surface(g_menu, des, 0, 0);
		for (size_t i = 0; i < kItemmenu; i++)
		{
			text_menu[i].render_text(font_, des);
		}
		while (SDL_PollEvent(&m_event))
		{
			switch (m_event.type)
			{
			case SDL_MOUSEMOTION:
				xc = m_event.motion.x;
				yc = m_event.motion.y;
				for (size_t j = 0; j < kItemmenu; j++)
				{
					if (SDL_commonFunction::check_colision_menu(xc, yc, text_menu[j].get_rect()) == true) {
						text_menu[j].set_color_text(text_object_::RED_TEXT);
						
					}
					else {
						text_menu[j].set_color_text(text_object_::BLACK_TEXT);
						
					}
				}
				break;
			case SDL_QUIT:
				return 1;
			case SDL_MOUSEBUTTONDOWN:
				xc = m_event.button.x;
				yc = m_event.button.y;
				for (size_t j = 0; j < kItemmenu; j++)
				{
					if (check_colision_menu(xc, yc, text_menu[j].get_rect()) == true) {
						return j;
					}
				}
				break;
			case SDL_KEYDOWN:
				if (m_event.key.keysym.sym == SDLK_ESCAPE) {
					return 1;
				}
				break;
			default:
				break;
			}

		}

	SDL_Flip(des);
	}
	
}

SDL_Surface* SDL_commonFunction::Load_Image(string file_path) {
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
SDL_Rect SDL_commonFunction::Apply_Surface(SDL_Surface* str, SDL_Surface* des, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(str, NULL, des, &offset);
	return offset;
}
void SDL_commonFunction::Apply_surface_Ex(SDL_Surface* str, SDL_Surface* des, SDL_Rect clip_, int x, int y) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(str, &clip_, des, &offset);
}

void SDL_commonFunction::Clean_Up() {
	SDL_FreeSurface(g_Screen);
	SDL_FreeSurface(g_Image);
	SDL_Quit();
}
bool SDL_commonFunction::check_collision(const SDL_Rect& offset_a, const SDL_Rect& offset_b) {

	const int left_a = offset_a.x;
	const int right_a = offset_a.x + offset_a.w;
	const int top_a = offset_a.y;
	const int button_a = offset_a.y + offset_a.h;

	const int left_b = offset_b.x;
	const int right_b = offset_b.x + offset_b.w;
	const int top_b = offset_b.y;
	const int button_b = offset_b.y + offset_b.h;

	if (left_a > left_b && left_a < right_b+5) {
		if (top_a > top_b && top_a+5 < button_b) {
			return true;
		}
	}
	if (left_a > left_b && left_a < right_b+5) {
		if (button_a+5 > top_b && button_a < button_b) {
			return true;
		}
	}
	if (right_a-5 > left_b && right_a < right_b) {
		if (top_a>top_b&&top_a+5<button_b) {
			return true;
		}
	}
	if (right_a-5 > left_b && right_a < right_b) {
		if (button_a+5>top_b && button_a < button_b) {
			return true;
		}
	}
	if (button_a == button_b && top_a == top_b && left_a == left_b && right_a == right_b) {
		return true;
	}
	return false;
}