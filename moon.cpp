#include "moon.h"

Moon::Moon(double nx, double ny, int vx, int vy, QPixmap* pic): Cereal(nx, ny, vx, vy, pic){
	count =0;
}

Moon::~Moon(){
}

bool Moon::move(){
	count++;
	if( count ==15){
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
	}
	return true;
}
