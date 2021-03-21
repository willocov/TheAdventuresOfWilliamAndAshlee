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

bool Player::IsColliding(LevelController* level, GLOBALS::DIRECTION direction) {
	//Determine the coordinates of the players requested movement;
	float requestedX, requestedY;
	requestedX = x;
	requestedY = y;

	switch (direction)
	{
	case GLOBALS::UP:
		requestedY -= GLOBALS::MOVEMENT_SPEED_SCALE;
		break;
	case GLOBALS::DOWN:
		requestedY += GLOBALS::MOVEMENT_SPEED_SCALE;
		break;
	case GLOBALS::LEFT:
		requestedX -= GLOBALS::MOVEMENT_SPEED_SCALE;
		break;
	case GLOBALS::RIGHT:
		requestedX += GLOBALS::MOVEMENT_SPEED_SCALE;
		break;
	default:
		break;
	}

	//Quick check to see if requested coordinates are out of bounds
	if (requestedX < 0 || requestedY < 0)
		return true;
	
	//Loop through the vector of collision objects and check if the players requested movement 
	//will place them inside a collision

	for (int i = 0; i < level->collisions.size(); i++) {
		Collision tempCollision = level->collisions[i];
		// collision_x < requested_x < collision_x + width
		
		/*cout << "Requested X: " << requestedX << endl;
		cout << "Requested Y: " << requestedY << endl;
		cout << "Collision X1: " << tempCollision.x << endl;
		cout << "Collision X2: " << tempCollision.x + tempCollision.width << endl;
		cout << "Collision Y1: " << tempCollision.y << endl;
		cout << "Collision Y2: " << tempCollision.y + tempCollision.height << endl << endl;*/

		//Checks if the requested x coordinate is within the bounds of the object
		if ((tempCollision.x <= requestedX && requestedX <= tempCollision.x + tempCollision.width)) {
			//Check for y coordinate now
			if ((tempCollision.y <= requestedY ) && (requestedY <= (tempCollision.y + tempCollision.height) )) {
				return true;
			}
		}
	}


	return false;
}