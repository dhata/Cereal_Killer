#ifndef DIAMOND_H
#define DIAMOND_H
#include "cereal.h"

class Diamond: public Cereal{

public:
	/** default constructor. sets the diamnd's initial positon, velocities, and sets the QPixmap. sets the type to 'D' */
	Diamond(double nx, double ny, int vx, int vy, QPixmap* pic, int dir);
	/** default deconstructor. doesn't do anything */
	~Diamond();
	/** moves the diamond forward. depending on what direction the diamond enters the game area from, x or y velocity switches positive/negative every 15 movements to create zig zag movement. */
	bool move();
	
private:
	/** keeps track of number of calls to move. actual movement occurs only every 15 calls to move */
	int count;
	/** zig zags every 15 movements in move */
	int count2;
	/** direction that the diamond was created from. controls which way the diamond zig zags. */
	int dir_;

};
	

#endif
