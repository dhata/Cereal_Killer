#include "star.h"

Star::Star(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
	type='S';
}

Star::~Star(){
}

bool Star::move(){
	count++;
	if(count==20){
		/*x+=velocityX;
		y+=velocityY;
		if(x<-50 || y<-50 || (x)>700 || (y) > 475){
			return false;
		}*/
		x += velocityX;
	    	y += velocityY;
	    	moveBy(velocityX, velocityY);

	    	if ( x < 0 ) {
			velocityX = -velocityX;
			x +=velocityX;
			moveBy(velocityX,0);
	    	}

	    	if ( y < 0 ) {
			velocityY = -velocityY;
			y +=velocityY;
			moveBy(0, velocityY);
	    	}

	    	if ( (x+50) > 680 ) {
		 	velocityX = -velocityX;
		 	x+=velocityX;
		 	moveBy(velocityX, 0);
	    	}

	    	if ( (y+50) > 475 ) {
		 	velocityY = -velocityY;
		 	y+=velocityY;
		 	moveBy(0, velocityY);
	    	}
		count=0;
		//moveBy(velocityX, velocityY);
		velocityX=rand()%20 -10;
		velocityY=rand()%20 -10;
	}
	
	return true;
}

