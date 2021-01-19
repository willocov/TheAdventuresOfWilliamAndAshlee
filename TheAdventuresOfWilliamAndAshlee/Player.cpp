#include "Player.h"

Player::Player() {
	//Player Spawn Location
	x = 100;
	y = 100;
}

void Player::MoveUp() {
	if (y > 0) {
		y -= GLOBALS::MOVEMENT_SPEED_SCALE;
	}
}

void Player::MoveDown() {
	y += GLOBALS::MOVEMENT_SPEED_SCALE;
}

void Player::MoveLeft() { x -= GLOBALS::MOVEMENT_SPEED_SCALE; }

void Player::MoveRight() { x += GLOBALS::MOVEMENT_SPEED_SCALE; }