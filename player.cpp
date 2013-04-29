#include "player.h"

Player::Player(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
	type='P';
}

Player::~Player(){
}

bool Player::move(){
	count++;
	if(count==20){
		x+=velocityX;
		y+=velocityY;
		count=0;
		if(x<0 || (x+73)>700 ){
			x-=velocityX;
			y-=velocityY;
		}
		else {
		moveBy(velocityX, velocityY);
		}
	}
	
	return true;
}

void Player::moveR(){
	x+=velocityX;
	if((x+73)>700){
		x-=velocityX;
	} else {
		moveBy(velocityX, 0);
	}
}

void Player::moveL(){
	x-=velocityX;
	if(x<0){
		x+=velocityX;
	} else {
		moveBy(-velocityX, 0);
	}
}
