#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Sound {
public:
    int py;
    int hk;
    int gpc_hd1;
    int snd_bgm_hd1 = 0;
    int snd_se_hd1 = 0;

    void update(float delta_time);
    void draw();

};

extern Sound sound;