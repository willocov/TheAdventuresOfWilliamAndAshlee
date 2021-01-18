#include "Player.h"

Player::Player() {
	x = 100;
	y = 100;
}

void Player::MoveUp() {
	if (y > 0) {
		y -= 10;
	}
}

void Player::MoveDown() {
	y += 10;
}

void Player::MoveLeft() { x -= 10; }

void Player::MoveRight() { x += 10; }