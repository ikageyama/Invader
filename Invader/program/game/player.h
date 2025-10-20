#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Player {
public:
    static constexpr int MOVE_SPEED = 5;
    static constexpr int SIZE_WIDTH = 100;
    static constexpr int SIZE_HEIGHT = 30;
    tnl::Vector3 pos_ = { (int)DXE_WINDOW_WIDTH / 2, (int)DXE_WINDOW_HEIGHT * 0.8f, 0 };

    void update(float delta_time);
    
};

extern Player player;
