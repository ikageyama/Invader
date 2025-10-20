#include <string>
#include "../dxlib_ext/dxlib_ext.h"

class Title {
public:
	enum {
		SCENE_ID_TITLE,
		SCENE_ID_PLAY
	};

	int g_scene_id = SCENE_ID_TITLE;

	const std::string TITLE_LOGO_STR = "SPACEインベーダー";
	const tnl::Vector3 TITLE_LOGO_POS = { 330, 200, 0 };

	const std::string TITLE_START_STR = "start enter";
	const tnl::Vector3 TITLE_START_POS = { 620, 500, 0 };

	const std::string TITLE_END_STR = "end Z";
	const tnl::Vector3 TITLE_END_POS = { 620, 600, 0 };

	const float TITLE_MENU_FLASHINTIME = 0.5f; // タイトルシーンのメニューの点滅時間の定数
	float g_title_menu_flashing_time_cont = 0; // タイトルシーンのメニューの点滅時間のカウント変数
	bool g_is_title_menu_on_draw = true;// タイトルシーンのメニューの描画フラグ

	void update(float delta_time);
};