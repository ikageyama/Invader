#include "playerbullet.h"
#include "player.h"

Bullet::Bullet() {
    pos = player.pos_;
}

void Bullet::update(float delta_time) {
    pos.y += BULLET_SPEED * -1;
    
}

void Bullet::draw() {
    DrawBoxEx(pos, sizeW, sizeH, true, 255);
}