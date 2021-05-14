#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H

#include"common_function.h"
#include"base_Object.h"
#include"amo.h"
#include<vector>

#define  WIDTH_MAIN_OBJECT_ 77
#define  HIEGHT_MAIN_OBJECT_ 52
using namespace std;

class main_Object_ :public base_Object {
private:
	int x_val_;
	int y_val_;
	
	vector < amo_object*> list_amo;
public:
	main_Object_();
	~main_Object_();
	void Handle_Move();
	void Handle_Events(SDL_Event Events, Mix_Chunk* Sound_bullet[2]);

	void set_list_amo(vector < amo_object*> amo_list) { list_amo = amo_list; }
	vector<amo_object*> get_list_amo() { return list_amo; }

	void make_amo_plane(SDL_Surface* g_Screen_);
	void remo_amo_plane(const int &idx);
};

#endif // !MAIN_OBJECT_H_
