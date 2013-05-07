#ifndef CLOVER_H
#define CLOVER_H
#include "cereal.h"

class Clover: public Cereal{

public:
	/** default constructor. sets the clover's initial positon, velocities, and sets the QPixmap. sets the type to 'C' */
	Clover(double nx, double ny, int vx, int vy, QPixmap* pic, int level);
	/** default deconstructor. doesn't do anything */
	~Clover();
	/** moves forward for the first 15 calls to move, then reverses direction for the next 10 calls, moves forward again for next 15 calls, repeats. 
	 * returns false if the clover moves to a location outside of the game area. */
	bool move();
	
private:
	/** clover only moves every 15 times move is called. */
	int count;
	/** second counter that increases everytime the clover actually moves */
	int count2;

};
	

#endif
