#ifndef BALLOON_H
#define BALLOON_H
#include "cereal.h"

class Balloon: public Cereal{

public:
	/** default constructor. sets the balloon's initial positon, velocities, and sets the QPixmap. sets the type to 'B' */
	Balloon(double nx, double ny, int vx, int vy, QPixmap* pic);
	/** default deconstructor. doesn't do anything */
	~Balloon();
	/** balloon moves forward every 15 calls to move. moves straight. if the balloon moves outside of the game area, returns false. otherwise returns true. */
	bool move();
	
private:
	/** count keeps track of how many calls to move there have been, always a value between 0 and 15 */
	int count;

};
	

#endif
