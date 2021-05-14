#include"threats_object.h"

threats_object::threats_object() {
	Rect_.x = WIDTH;
	Rect_.y = HEIGHT * 0.5;
	Rect_.w = WIDTH_THREATS;
	Rect_.h = HEIGHT_THREATS;

	x_val_ = 0;
	y_val_ = 0;
}
threats_object ::~threats_object() {
	if (amo.size() > 0) {
		for (size_t i = 0; i < amo.size(); i++)
		{
			amo_object* amo__ = amo.at(i);
			if (amo__ != NULL) {
				delete amo__;
				amo__ = NULL;
			}
		}
		amo.clear();
	}
	
}

void threats_object::Handle_Move(const int& x_border, const int& y_border) {
	Rect_.x -= x_val_;
	if (Rect_.x < 0) {
		Rect_.x = WIDTH;
		int y_rand = rand() % 300;
		if (y_rand > HEIGHT - 200) {
			y_rand = HEIGHT * 0.3;
		}
		Rect_.y = y_rand;
	}

}
void threats_object::Handle_Input() {
	// to do;
}

void threats_object::set_x_val_(const int& x) {
	x_val_ = x;
}

void threats_object::set_y_val(const int& y) {
	y_val_ = y;
}

void threats_object::Init_amo(amo_object* p_amo) {
	if (p_amo != NULL) {
		bool arr = p_amo->Load_("sphere_threats.png");
		if (arr) {
			p_amo->setWidthHieght(WIDTH_SPHERE, HIEGHT_SPHERE);
			p_amo->set_is_move(true);
			p_amo->set_type_amo(amo_object::SPHERE);
			p_amo->set_x_val(10);
			p_amo->Set_Rect_(Rect_.x, Rect_.y + HEIGHT_THREATS * 0.5);
			amo.push_back(p_amo);
		}
	}
}
void threats_object::make_amo(SDL_Surface* des, const int& x_border, const int& y_border) {
	for (size_t i = 0; i < amo.size(); i++)
	{
		amo_object* amo_p = amo.at(i);
		if (amo_p->get_is_move()) {
			amo_p->handle_Move_Amo_From_Threats(x_border, y_border);
			amo_p->Show_(des);
		}
		else {
			amo_p->set_is_move(true);
			amo_p->Set_Rect_(Rect_.x, Rect_.y + HEIGHT_THREATS * 0.5);
		}
	}
}
void threats_object::remove_threats(const int& xborder) {
	Rect_.x = xborder;
	int y_rand = rand() % 300;
	if (y_rand > HEIGHT - 200) {
		y_rand = HEIGHT * 0.3;
	}
	Rect_.y = y_rand;
	for (size_t ip = 0; ip < amo.size(); ip++)
	{
		amo_object* amop = amo.at(ip);
		if (amop) {
			resets_amo(amop);
		}
	}
}
void threats_object::resets_amo(amo_object*poamo) {
	poamo->Set_Rect_(Rect_.x, Rect_.y + HEIGHT_THREATS * 0.5);
}