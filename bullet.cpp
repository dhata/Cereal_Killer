#include "bullet.h"

Bullet::Bullet(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
}

Bullet::~Bullet(){
}

bool Bullet::move(){
	count++;
	if(count==20){
		//x+=velocityX;
		y+=velocityY;
		if(y<0){
			return false;
		}
		count=0;
		moveBy(0, velocityY);
	}
	
	return true;
}
