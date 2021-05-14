#include"common_function.h"
#include"main_Object.h"
#include"amo.h"
#include"threats_object.h"
#include"Explosion_Object.h"
#include"player_number.h"
#include"text_object.h"

TTF_Font* font_text=NULL;
TTF_Font* font_text1 = NULL;

bool INIT() {
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	g_Screen = SDL_SetVideoMode(WIDTH, HEIGHT, BPP, SDL_SWSURFACE);
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
		return false;
	}
	S_Amo[0] = Mix_LoadWAV("s_laser.wav");
	S_Amo[1] = Mix_LoadWAV("s_sphere.wav");
	S_Colision = Mix_LoadWAV("s_no.wav");
	S_Game_Over = Mix_LoadWAV("s_gameover.wav");
	S_Background = Mix_LoadWAV("LaLung-Vu-4749614.wav");
	S_B = Mix_LoadMUS("s_background.wav");
	if (S_Background == NULL || S_Amo[0] == NULL || S_Amo[1] == NULL || S_Colision == NULL, S_Game_Over == NULL) {
		return 1;
	}
	if (TTF_Init() == -1) {
		return false;
	}
	font_text = TTF_OpenFont("unicod.ttf", 20);
	font_text1 = TTF_OpenFont("thuphap.ttf", 50);
	if (font_text == NULL) {
		return false;
	}

	return true;
}

int main(int arc, char* argv[]) {
	//khoi tao am thanh
	int loop = 0;
	int mark = 0;
	bool is_move_screen = true;
	int x_offset_screen = 0;

	bool is_quit = false;
	if (INIT() == false) {
		return 1;
	}
	g_Image = SDL_commonFunction::Load_Image("background2.png");
	//load anh plane
	main_Object_ plane;
	plane.Set_Rect_(300, 200);
	bool arr = plane.Load_("plane_fly.png");
	if (!arr) {
		return 1;
	}
	threats_object* threats_ = new threats_object[NUM_THREATS];

	for (size_t j = 0; j < NUM_THREATS; j++)
	{
		threats_object* threats = (threats_ + j);
		if (threats) {
			bool thre = threats->Load_("threats.png");
			if (thre == false) {
				return 1;
			}
			int y_rand = rand() % 300;
			if (y_rand > HEIGHT - 200) {
				y_rand = HEIGHT * 0.3;
			}
			threats->Set_Rect_(WIDTH + j * 350, y_rand);
			threats->set_x_val_(5);

			amo_object* P_amo = new amo_object();
			threats->Init_amo(P_amo);
		}
	}

	//declare player_number
	int number_player_ = 3;
	player_number player;
	player.set_number_player(number_player_);
	player.Init_player();
	//
	text_object_ text_;
	text_.set_color_text(text_object_::WHILE_TEXT);
	//
	text_object_ time_;
	text_.set_color_text(text_object_::BLACK_TEXT);
	//declare explosion:

	Ex_Object Explosion_;
	bool b_exp = Explosion_.Load_("exp_main.png");
	Explosion_.set_clip();
	if (b_exp == false) {
		return 1;
	}

	//Mix_PlayChannel(-1, S_Background, 0);
	// start while loop
	int a = 1;
	int _menu = SDL_commonFunction::show_menu_(g_Screen, font_text1);
	if (_menu == 1) {
		is_quit = true;
	}
	while (!is_quit)
	{
		//Mix_PlayMusic(S_B, 0);
		if (loop == 0) {
		Mix_PlayChannel(-1, S_Background, -1);
		   loop++;
		}

		while (SDL_PollEvent(&g_Event))
		{
			if (g_Event.type == SDL_QUIT) {
				is_quit = true;
				break;
			}

			/*Mix_PlayChannel(-1, S_Background, 0);*/

			plane.Handle_Events(g_Event, S_Amo);
		}

		// chuyen dong man hinh screen
		if (is_move_screen == true) {
			x_offset_screen -= 2;
			if (x_offset_screen <= -(WIDTH_BACKGROUND - WIDTH))
			{
				x_offset_screen = 0;
			}
			else {
				SDL_commonFunction::Apply_Surface(g_Image, g_Screen, x_offset_screen, 0);
			}
		}
		else
		{
			SDL_commonFunction::Apply_Surface(g_Image, g_Screen, x_offset_screen, 0);
		}

		// chuyen dong cua may bay
		plane.Handle_Move();
		plane.Show_(g_Screen);
		//tao dan tu plane
		plane.make_amo_plane(g_Screen);
		// khoi tao 3 moi hiem hoa

		for (size_t k = 0; k < NUM_THREATS; k++)
		{
			threats_object* threatss = (threats_ + k);
			if (threatss) {
				threatss->Handle_Move(WIDTH, HEIGHT * 0.5);
				threatss->Show_(g_Screen);
				// dan tu threats
				threatss->make_amo(g_Screen, WIDTH, HEIGHT);

				// su ly va cham giua plane -> amo
				vector<amo_object*> amot = threatss->get_amo();
				for (size_t at = 0; at < amot.size(); at++)//3 vien dan
				{
					if (amot.at(at) != NULL) {

						bool prr = SDL_commonFunction::check_collision(amot.at(at)->get_rect(), plane.get_rect());
						if (prr == true) {
							//am thanh
							Mix_PlayChannel(-1, S_Game_Over, 0);
							
							//hieu ung no
							for (size_t ex = 0; ex < 4; ex++)
							{
								int x_post = (plane.get_rect().x + plane.get_rect().w * 0.5) - EX_WIDTH * 0.5;
								int y_post = (plane.get_rect().y + plane.get_rect().h * 0.5) - EX_HEIGHT * 0.5;
								Explosion_.set_frame(ex);
								Explosion_.show_Ex(g_Screen, x_post, y_post);
								SDL_Flip(g_Screen);
							}
							// su ly mat mang.
							number_player_--;
							if (number_player_ > 0) {
								player.set_number_player(number_player_);
								player.show_player(g_Screen);
								SDL_Flip(g_Screen);
								SDL_Delay(1000);
								plane.Set_Rect_(300, 200);
								player.resize();
								threatss->resets_amo(amot.at(at));
								
							}
							//Game Over
							else {
								time_.Set_Rect_(WIDTH - 200, 10);
								time_.render_text(font_text, g_Screen);
								text_.render_text(font_text, g_Screen);
								SDL_Flip(g_Screen);
								if (MessageBox(NULL, L"Game_Over!", L"InFo", MB_OK) == IDOK) {
									delete[] threats_;
									SDL_commonFunction::Clean_Up();
									return 0;
								}
							}

						}
					}
				}

			}
			// va cham plane voi threats
			bool prr = SDL_commonFunction::check_collision(plane.get_rect(), threatss->get_rect());
			if (prr == true) {
				//xu ly vu no
				Mix_PlayChannel(-1, S_Game_Over, 0);
				//hieu ung vu no
				for (size_t ex = 0; ex < 4; ex++)
				{
					int x_post = (plane.get_rect().x + plane.get_rect().w * 0.5) - EX_WIDTH * 0.5;
					int y_post = (plane.get_rect().y + plane.get_rect().h * 0.5) - EX_HEIGHT * 0.5;
					Explosion_.set_frame(ex);
					Explosion_.show_Ex(g_Screen, x_post, y_post);
					SDL_Flip(g_Screen);
				}
				//su ly mat mang
				number_player_--;
				if (number_player_ > 0) {
					SDL_Delay(1000);
					plane.Set_Rect_(300, 200);
					player.resize();
					threatss->remove_threats(WIDTH);
				}
				//Game Over
				else {
					time_.Set_Rect_(WIDTH - 200, 10);
					time_.render_text(font_text, g_Screen);
					text_.render_text(font_text, g_Screen);
					SDL_Flip(g_Screen);
					if (MessageBox(NULL, L"Game_Over!", L"InFo", MB_OK) == IDOK) {
						delete[] threats_;
						SDL_commonFunction::Clean_Up();
						return 0;
					}
				}
			}
			//va cham threats->amo of plane
			vector<amo_object*> list_amo = plane.get_list_amo();
			for (size_t ii = 0; ii < list_amo.size(); ii++)
			{
				amo_object* p_amo = list_amo.at(ii);
				if (p_amo != NULL) {
					bool test_col = SDL_commonFunction::check_collision(p_amo->get_rect(), threatss->get_rect());
					if (test_col == true) {
						mark++;
						//hieu ung vu no
						for (size_t ex = 0; ex < 4; ex++)
						{
							int x_post = (p_amo->get_rect().x + p_amo->get_rect().w * 0.5) - EX_WIDTH * 0.5;
							int y_post = (p_amo->get_rect().y + p_amo->get_rect().h * 0.5) - EX_HEIGHT * 0.5;
							Explosion_.set_frame(ex);
							Explosion_.show_Ex(g_Screen, x_post, y_post);
							SDL_Flip(g_Screen);
						}

						//remove thang threats
						threatss->remove_threats(WIDTH);
						plane.remo_amo_plane(ii);
						//am thanh 
						Mix_PlayChannel(-1, S_Colision, 0);
					}
				}

			}
			

		}
		Uint32 time_val = SDL_GetTicks() / 1000;//chuc nang la lay thoi gian ma chuong trinh da chay khi goi den no
		string time = "Time: ";
		string tiem_v = time+to_string(time_val);
		time_.set_text_name(tiem_v);
		time_.Set_Rect_(WIDTH - 200, 10);
		time_.render_text(font_text, g_Screen);

		string name_ = "Mark: ";
		string mark_ = to_string(mark);
		string apply_ = name_ + mark_;
		text_.set_text_name(apply_);
		text_.render_text(font_text, g_Screen);
		
		player.set_number_player(number_player_);
		player.show_player(g_Screen);

		SDL_Flip(g_Screen);

	}
	delete[] threats_;

	SDL_commonFunction::Clean_Up();
	return 0;
}