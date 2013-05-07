#ifndef PLAYER_H
#define PLAYER_H
#include "cereal.h"
#include <cmath>

class Player: public Cereal{

public:
	/** default constructor. sets the player's initial positon, velocities, and sets the QPixmap. sets the type to 'P' */
	Player(double nx, double ny, int vx, int vy, QPixmap* pic, int level);
	/** default deconstructor. doesn't do anything */
	~Player();
	/** moves the player, constrained to staying in the game area. should never be called based on this game. */
	bool move();
	/** moves the player right, constrained to staying in the game area. if the player has reached the edge, then it does not move. */
	void moveR();
	/** move the player left, constrained to staying in the game area. if the player has reached the edge, then it does not move. */
	void moveL();
	
private:
	

};
	

#endif
