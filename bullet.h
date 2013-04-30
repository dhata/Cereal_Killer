#ifndef BULLET_H
#define BULLET_H
#include "cereal.h"
#include <cmath>

class Bullet: public Cereal{

public:
	/** default constructor. sets the bullet's initial positon, velocities, and sets the QPixmap. sets the type to 'b' */
	Bullet(double nx, double ny, int vx, int vy, QPixmap* pic);
	/** default deconstructor. doesn't do anything */
	~Bullet();
	/** moves the bullet straight forward. if the bullet reaches the edge of the game area, then it returns false. */
	bool move();
	
private:
	/** the bullet only moves every 15 calls to move */
	int count;

};
	

#endif
