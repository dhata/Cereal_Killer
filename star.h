#ifndef STAR_H
#define STAR_H
#include "cereal.h"
#include <cmath>

class Star: public Cereal{

public:
	/** default constructor. sets the star's initial positon, velocities, and sets the QPixmap. sets the type to 'S' */
	Star(double nx, double ny, int vx, int vy, QPixmap* pic, int level);
	/** default deconstructor. doesn't do anything */
	~Star();
	/** star moves a random direction N, S, E, or W. moves, then generates random velocities for the next call to move. if it reaches the edge of the game area, then it moves back into the game area */
	bool move();
	
private:
	/** star only moves every 20 calls to move */
	int count;

};
	

#endif
