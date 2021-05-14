
#include"main_Object.h"
#include"amo.h"

main_Object_::main_Object_() {
	x_val_ = 0;
	y_val_ = 0;
	Rect_.x = 0;
	Rect_.y = 0;
	Rect_.w = WIDTH_MAIN_OBJECT_;
	Rect_.h = HIEGHT_MAIN_OBJECT_;
	
}
main_Object_::~main_Object_() {
	;
}
void main_Object_::Handle_Move() {
	Rect_.x += x_val_;
	if (Rect_.x<0 || Rect_.x + WIDTH_MAIN_OBJECT_>WIDTH) {
		Rect_.x -= x_val_;
	}
	Rect_.y += y_val_;
	if (Rect_.y<0 || Rect_.y + HIEGHT_MAIN_OBJECT_>HEIGHT-200) {
		Rect_.y -= y_val_;
	}
}
void main_Object_::Handle_Events(SDL_Event Events,Mix_Chunk*Sound_bullet[2]) {
	if (Events.type == SDL_KEYDOWN) {
		switch (Events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ -= HIEGHT_MAIN_OBJECT_ / 4;
			break;
		case SDLK_DOWN:
			y_val_ += HIEGHT_MAIN_OBJECT_ / 4;
			break;
		case SDLK_LEFT:
			x_val_ -= WIDTH_MAIN_OBJECT_ / 4;
			break;
		case SDLK_RIGHT:
			x_val_ += WIDTH_MAIN_OBJECT_ / 4;
			break;

		default:
			break;
		}
	}
	else if (Events.type == SDL_KEYUP) {

		switch (Events.key.keysym.sym)
		{
		case SDLK_UP:
			y_val_ += HIEGHT_MAIN_OBJECT_ / 4;
			break;
		case SDLK_DOWN:
			y_val_ -= HIEGHT_MAIN_OBJECT_ / 4;
			break;
		case SDLK_LEFT:
			x_val_ += WIDTH_MAIN_OBJECT_ / 4;
			break;
		case SDLK_RIGHT:
			x_val_ -= WIDTH_MAIN_OBJECT_ / 4;
			break;

		default:
			break;
		}
	}
	else if (Events.type == SDL_MOUSEBUTTONDOWN) {
		amo_object* tem_amo=new amo_object();
		if (Events.button.button == SDL_BUTTON_LEFT) {
			Mix_PlayChannel(-1, Sound_bullet[0], 0);
			tem_amo->set_type_amo(amo_object::LASER);
			tem_amo->setWidthHieght(WIDTH_LASER, HIEGHT_LASER);
			tem_amo->Load_("laser.png");
			
		}
		else if (Events.button.button == SDL_BUTTON_RIGHT) {
			Mix_PlayChannel(-1, Sound_bullet[0], 0);
			tem_amo->set_type_amo(amo_object::SPHERE);
			tem_amo->setWidthHieght(WIDTH_SPHERE, HIEGHT_SPHERE);
			tem_amo->Load_("star.png");
			
		}
		 
		 tem_amo->Set_Rect_(this->Rect_.x+this->Rect_.w-35,this->Rect_.y+this->Rect_.h*0.78);
		 tem_amo->set_is_move(true);
		 tem_amo->set_x_val(20);
		 list_amo.push_back(tem_amo);
	}
	else if (Events.type == SDL_MOUSEBUTTONUP) {
		
	}
}

void main_Object_::make_amo_plane(SDL_Surface* g_Screen_) {
	for (size_t i = 0; i < list_amo.size(); i++)
	{
		amo_object* Amo = list_amo.at(i);
		if (Amo != NULL) {

			if (Amo->get_is_move()) {
				Amo->handle_Move(WIDTH, HEIGHT);
				Amo->Show_(g_Screen_);
			}
			else {
				if (Amo != NULL) {
					list_amo.erase(list_amo.begin() + i);
					set_list_amo(list_amo);
					delete Amo;
					Amo = NULL;
				}
			}

		}

	}

}
void main_Object_::remo_amo_plane(const int& idx) {
	amo_object* amooi = list_amo.at(idx);
	if (amooi != NULL) {
		list_amo.erase(list_amo.begin() + idx);
		if (amooi != NULL) {
			delete amooi;
			amooi = NULL;
		}
	}
}