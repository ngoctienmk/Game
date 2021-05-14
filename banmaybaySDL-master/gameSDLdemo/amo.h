#ifndef AMO_H_
#define AMO_H_

#include"base_Object.h"

#define	WIDTH_LASER 35
#define HIEGHT_LASER 5

#define WIDTH_SPHERE 10
#define HIEGHT_SPHERE 10


class amo_object : public base_Object {
private:
	int x_val_;
	int y_val_;
	int type_amo;
	bool is_move;
public:
	enum type_amo_
	{
		NONE,
		LASER,
		SPHERE
	};
	amo_object();
	~amo_object();
	void handleInputEvent();
	void handle_Move(const int & x_border,const int & y_border);
	void handle_Move_Amo_From_Threats(const int& x_border, const int& y_border);

	void set_type_amo(int type) { type_amo = type; }
	int get_type_amo() {return type_amo; }

	void set_is_move(bool is_move_) { is_move = is_move_; }
	bool get_is_move() { return is_move; }

	void set_x_val(const int& x_val);
	int get_x_val() { return x_val_; }

	void set_y_val(const int& y_val);
	int get_y_val() { return y_val_; }

	void setWidthHieght(const int &w, const int &h) { Rect_.w = w; Rect_.h = h; }
};

#endif // !AMO_H_

