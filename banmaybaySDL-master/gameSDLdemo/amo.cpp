#include"amo.h"

amo_object::amo_object() {
	x_val_ = 0;
	y_val_ = 0;
	Rect_.x = 0;
	Rect_.y = 0;
	is_move = false;
	type_amo = NONE;
}
amo_object::~amo_object() {
	;// to do
}
void amo_object::handleInputEvent() {
	;//
}
void amo_object::handle_Move(const int& x_border, const int& y_border) {
	if (is_move == true) {
		Rect_.x += x_val_;
		if (Rect_.x > x_border) {
			is_move = false;
		}
	}
}
void amo_object::handle_Move_Amo_From_Threats(const int& x_border, const int& y_border)
{
	if (is_move == true) {
		Rect_.x -= x_val_;
		if (Rect_.x < 0) {
			is_move = false;
		}
	}
}
void amo_object::set_x_val(const int& x_val) {
	x_val_ = x_val;
}

void amo_object::set_y_val(const int& y_val) {
	y_val_ = y_val;
}

