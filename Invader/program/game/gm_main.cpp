#include <time.h>
#include <string>
#include <stdio.h>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"
#include "player.h"
#include"playerbullet.h"
#include"sound.h"
#include"title.h"

#define Y_enemy 15 

Player player;
Bullet bullet;
Sound sound;
Title title;

const int total_Bullet = 999;  //出せる弾の上限
class Bullet* b[total_Bullet] = { nullptr };
int numBullet = 0;
int numDelete = 0;

void new1();// 初期化関数

int score = 0;
int gpc_hd1;
int pos_x;
int pos_y[Y_enemy] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int pos_[15][Y_enemy];///横15マス、縦Y_enemy
int bullet_1;
int j, k;
int A = 0;
int CNT = 0;
int HD = 5;//頻度
int KR = 2;//距離
int KT = 0;//カウント数
int second = 0;//時間

enum {
    SCENE_ID_TITLE,
    SCENE_ID_PLAY,
    SCENE_ID_END
};

int g_scene_id = SCENE_ID_TITLE;

const std::string space = "スペースで弾が\n発射できます。";

const std::string end = "oでタイトルに\n戻ります。";

const std::string end2 = "oでタイトルに戻ります。";

const std::string kuria = "Thank you for playing !!";

void sceneTitle(float delta_time) {

    title.update(delta_time);

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_RETURN)) {
        g_scene_id = SCENE_ID_PLAY;
    }

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Z)) {
        exit(0); //ゲームの終了
    }

    new1();//初期化
    second = 0;//経過時間の初期化
}

void scenePlay(float delta_time) {

    player.update(delta_time);

    bullet.update(delta_time);

    sound.update(delta_time);

    srand((unsigned int)time(NULL));

    second++;//経過時間

    //敵　描画
    for (j = 0; j < 15; j++) {
        if (pos_[j][0] == 1) {
            pos_x = j * 80 + 20;
            DrawGraph(pos_x, pos_y[0], gpc_hd1, true);
        }

    }

    if (A > HD) { //敵が落ちる頻度
        pos_y[0] += KR;
        A = 0;
        if (KT == 840) { //14秒間
            HD--;

        }
        else if (KT >= 1680) {
            HD = 5;
            KR++;
            KT = 0;
        }

    }
    A++;
    for (int k = 1; k < Y_enemy && pos_y[k - 1] >= 100; k++) { //pos_y[k - 1] >= 100 [y座標が100の距離を移動したら敵が出現する] 
        for (j = 0; j < 15; j++) {
            if (pos_[j][k] == 1) {
                pos_x = j * 80 + 20;
                DrawGraph(pos_x, pos_y[k], gpc_hd1, true);
            }
        }

        if (A > HD) {
            pos_y[k] += KR;

        }

        srand((unsigned int)time(NULL));
    }
    KT++;
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {

        if (numBullet < total_Bullet) {
            b[numBullet] = new Bullet(); //new Bullet「新しく弾が生成される」　b[弾を撃った回数]
            numBullet++;
        }
    }

    for (int i = numDelete; i < numBullet; i++) {
        b[i]->update(delta_time);//b[i]弾の構造体
        b[i]->draw();
        if (b[i]->pos.y < 0) {
            delete b[i];
            numDelete++;
        }
        for (k = 0; k < Y_enemy; k++) {
            for (j = 0; j < 15; j++) {
                if (b[i]->pos.x > (j * 80 + 10) && b[i]->pos.x <(j * 80 + 80) && b[i]->pos.y > pos_y[k] - 4 && b[i]->pos.y < pos_y[k] + 50) { //当たり判定
                    if (pos_[j][k] == 1) { // == 比較
                        b[i]->pos.x = 2000; //生きている敵に弾が当たったら弾を画面外に飛ばす
                        score = score + 50; //スコアの加算
                        pos_[j][k] = 0; //敵の生死判定「0は死んでいる」
                        CNT++;
                    }
                }
            }
        }

    }

    //速さレベル
    int B = KR - 1;

    //文字入力
    DrawStringEx(1300, 100, -1, "レベル%d", B);

    DrawStringEx(1300, 150, -1, "score = %d", score);

    SetFontSize(20);
    DrawStringEx(1280, 210, -1, space.c_str());

    SetFontSize(20);
    DrawStringEx(1280, 280, -1, end.c_str());

    //場面変更
    if (score == 50 * 15 * Y_enemy) {
        g_scene_id = SCENE_ID_END;
    }

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_O) || second >= 4320) {
        g_scene_id = SCENE_ID_TITLE;
    }
}

void sceneEnd(float delta_time) {

    SetFontSize(50);
    DrawStringEx(410, 250, -1, kuria.c_str());

    SetFontSize(30);
    DrawStringEx(550, 600, -1, end2.c_str());

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_O)) {
        g_scene_id = SCENE_ID_TITLE;
    }

}

void new1()
{
    score = 0;
    A = 0;
    CNT = 0;
    HD = 5;//頻度
    KR = 2;//距離
    KT = 0;//カウント数
    numBullet = 0;
    numDelete = 0;

    //敵を復元させる
    for (k = 0; k < Y_enemy; k++) {
        pos_y[k] = 0;         //y座標の初期化
        for (j = 0; j < 15; j++) { //敵を生存判定にする
            pos_[j][k] = 1;
        }
    }

    return;
}

void gameStart(){
	srand(time(0));

    sound.draw();

	gpc_hd1 = LoadGraph("graphics/teki2.png");

	// 敵　生存判定
	for (k = 0; k < Y_enemy; k++) {
		for (j = 0; j < 15; j++) {
			pos_[j][k] = 1;
		}
	}
}


void gameMain(float delta_time) {
    switch (g_scene_id) {
    case SCENE_ID_TITLE:
        sceneTitle(delta_time);
        break;
    case SCENE_ID_PLAY:
        scenePlay(delta_time);
        break;
    case SCENE_ID_END:
        sceneEnd(delta_time);
        break;
    }
}


void gameEnd() {

}