#ifndef MOON_H
#define MOON_H
#include "cereal.h"

class Moon: public Cereal{

public:
	/** default constructor. sets the moon's initial positon, velocities, and sets the QPixmap. sets the type to 'M' */
	Moon(double nx, double ny, int vx, int vy, QPixmap* pic, int level);
	/** default deconstructor. doesn't do anything */
	~Moon();
	/** moves the moon in the game area. when it reaches the end, it reverses direction. always returns true because it never moves outside of the game area. */
	bool move();
	
private:
	/** moon moves every 15th call to move. */
	int count;

};
	

#endif
