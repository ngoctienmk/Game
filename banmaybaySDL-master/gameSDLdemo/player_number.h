#ifndef PLAYER_NUMBER_H_
#define PLAYER_NUMBER_H_
#include"base_Object.h"
#include<vector>

const int WIDTH_PLAYER = 40;
const int HEIGHT_PLAYER = 40;

class player_number :public base_Object {
private:
	int number_player;
	vector<int> location;
public:
	player_number();
	~player_number();
	void set_number_player(const int& num) { number_player = num; }
	void Init_player();
	void resize();
	void show_player(SDL_Surface* des);
	void pos_location(const int &lc);

};

#endif // !PLAYER_NUMBER_H_
