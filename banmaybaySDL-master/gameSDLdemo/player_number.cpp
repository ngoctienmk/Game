#include"player_number.h"

player_number::player_number() {
	Rect_.y = 0;
	number_player = 3;
}
player_number ::~player_number() {
	//todo;
}
void player_number::pos_location(const int& lc) {
	location.push_back(lc);
}
void player_number::Init_player() {
	Load_("player_number.png");
	if (Image_ != NULL) {
		if (location.size() > 0) {
			location.clear();
		}
		pos_location(20);
		pos_location(60);
		pos_location(100);
	}
	
}
void player_number::show_player(SDL_Surface*des) {
	if (location.size() > 0) {
		for (size_t i = 0; i < number_player; i++)
		{
			Rect_.x = location.at(i);
			Show_(des);
		}
	}
}
void player_number::resize() {
	location.pop_back();

}