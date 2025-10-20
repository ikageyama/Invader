#include "player.h"

void Player::update(float delta_time) {
    if (tnl::Input::IsKeyDown(eKeys::KB_LEFT))pos_.x -= Player::MOVE_SPEED;
    if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT))pos_.x += Player::MOVE_SPEED;
}


