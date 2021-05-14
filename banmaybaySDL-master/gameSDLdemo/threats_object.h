#ifndef THREATS_OBJECT_H_
#define THREATS_OBJECT_H_

#include"base_Object.h"
#include"amo.h"
#include<vector>

#define WIDTH_THREATS 80
#define HEIGHT_THREATS 33

class threats_object :public base_Object {
private:
	int x_val_;
	int y_val_;
	vector <amo_object*> amo;
public:
	threats_object();
	~threats_object();

	void Handle_Move(const int &x_border,const int & y_border);
	void Handle_Input();

	void set_x_val_(const int& x);
	int get_x_val_() { return x_val_; }

	void set_y_val(const int& y);
	int get_y_val() { return y_val_; }

	void Init_amo(amo_object* p_amo);
	void make_amo(SDL_Surface*des,const int &x_border,const int &y_border);
	vector<amo_object*> get_amo() { return amo; }
	//ham su ly va cham giua dan cua may bay va threats
	void remove_threats(const int &xborder);
	void resets_amo(amo_object* poamo);


};

#endif // !THREATS_OBJECT_H_
