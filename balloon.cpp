#include "balloon.h"

Balloon::Balloon(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
}

Balloon::~Balloon(){
}

bool Balloon::move(){
	count++;
	if(count==15){
		x+=velocityX;
		y+=velocityY;
		if(x<0 || y<0 || (x+50)>700 || (y+50) > 475){
			return false;
		}
	//
		//x+=velocityX;
		//y+=velocityY;
		count=0;
		moveBy(velocityX, velocityY);
		
		//setPos(x,y);
	}
	return true;
}
