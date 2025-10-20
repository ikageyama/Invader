#include"sound.h"
#include"player.h"

void Sound::draw() {

    //ÉvÉåÉCÉÑÅ[
    py = LoadGraph("graphics/char_test.png");

    //îwåi
    hk = LoadGraph("graphics/haikei.jpg");
    
    //ìG
    gpc_hd1 = LoadGraph("graphics/teki2.png");

    //BGM
    snd_bgm_hd1 = LoadSoundMem("sound/í«ê’é“.mp3");

    //íeÇÃî≠éÀâπ
    snd_se_hd1 = LoadSoundMem("sound/se_pyun3.mp3");
    PlaySoundMem(snd_bgm_hd1, DX_PLAYTYPE_LOOP);
}

void Sound::update(float delta_time) {
    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_SPACE)) {
        PlaySoundMem(snd_se_hd1, DX_PLAYTYPE_BACK);
    }

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_Z)) {
        StopSoundMem(snd_bgm_hd1);
    }

    if (tnl::Input::IsKeyDownTrigger(eKeys::KB_X)) {
        PlaySoundMem(snd_bgm_hd1, DX_PLAYTYPE_LOOP, false);
    }

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);

    DrawRotaGraph(DXE_WINDOW_WIDTH / 2, DXE_WINDOW_HEIGHT / 2, 1.0f, 0, hk, true);

    DrawGraph(player.pos_.x -17, (int)DXE_WINDOW_HEIGHT * 0.8f - 30, py, true);

    

}
