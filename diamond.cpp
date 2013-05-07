#include "diamond.h"

Diamond::Diamond(double nx, double ny, int vx, int vy, QPixmap* pic, int dir, int level): Cereal(nx, ny, vx, vy, pic, level){
	count =0;
	count2=0;
	dir_=dir;
	type='D';
}

Diamond::~Diamond(){
}

bool Diamond::move(){
	count++;
	if(count==15){
		x+=velocityX;
		y+=velocityY;
		if(x<0 || y<0 || (x+50)>700 || (y+50) > 475){
			return false;
		}
	
		//x+=velocityX;
		//y+=velocityY;
		count=0;
		moveBy(velocityX, velocityY);
		count2++;
		if( count2==15){
			switch(dir_){
				case 0:	//from left
					velocityY*=-1;
					break;
				case 1: 
					velocityX*=-1;
					break;
				default:
					velocityY*=-1;
					break;
			}
		} 
		if (count2==30) {
			switch(dir_){
				case 0:	//from left
					velocityY*=-1;
					break;
				case 1: 
					velocityX*=-1;
					break;
				default:
					velocityY*=-1;
					break;
			}
			count2=0;
		}
	}
		//setPos(x,y);
	return true;
}
