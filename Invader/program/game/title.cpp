#include"title.h"

void Title::update(float delta_time) {
	g_title_menu_flashing_time_cont += delta_time;
	if (g_title_menu_flashing_time_cont > TITLE_MENU_FLASHINTIME) {
		g_is_title_menu_on_draw = !g_is_title_menu_on_draw;
		g_title_menu_flashing_time_cont = 0;
	}

	

	SetFontSize(100);
	DrawStringEx(TITLE_LOGO_POS.x, TITLE_LOGO_POS.y, -1, TITLE_LOGO_STR.c_str());

	if (g_is_title_menu_on_draw) {
		SetFontSize(35);
		DrawStringEx(TITLE_START_POS.x, TITLE_START_POS.y, -1, TITLE_START_STR.c_str());

		SetFontSize(35);
		DrawStringEx(TITLE_END_POS.x, TITLE_END_POS.y, -1, TITLE_END_STR.c_str());
	}
}