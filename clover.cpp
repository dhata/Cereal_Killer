#include "clover.h"

Clover::Clover(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
	count2=0;
	type='C';
}

Clover::~Clover(){
}

bool Clover::move(){
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
		count2++;
		if( count2==15){
			velocityX*=-1;
			velocityY*=-1;
		} 
		if (count2==25) {
			velocityX*=-1;
			velocityY*=-1;
			count2=0;
		}
	}
		//setPos(x,y);
	return true;
}
