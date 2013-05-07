#include "bullet.h"

Bullet::Bullet(double nx, double ny, int vx, int vy, QPixmap* pic, int level): Cereal(nx, ny, vx, vy, pic, level){
	count =0;
	type='b';	//C stands for crystal
}

Bullet::~Bullet(){
}

bool Bullet::move(){
	count++;
	if(count==15){
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
