#include "balloon.h"

Balloon::Balloon(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	//count =0;
}

Balloon::~Balloon(){
}

void Balloon::move(){
	count++;
	x+=velocityX;
	y+=velocityY;
	if(count==20){
		count=0;
		moveBy(velocityX, velocityY);
	}
	
}
