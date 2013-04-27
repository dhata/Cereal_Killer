#include "star.h"

Star::Star(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
}

Star::~Star(){
}

bool Star::move(){
	count++;
	if(count==20){
		x+=velocityX;
		y+=velocityY;
		if(x<-50 || y<-50 || (x)>700 || (y) > 475){
			return false;
		}
		count=0;
		moveBy(velocityX, velocityY);
		velocityX=rand()%20 -10;
		velocityY=rand()%20 -10;
	}
	
	return true;
}
