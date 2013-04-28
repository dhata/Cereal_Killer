#ifndef PLAYER_H
#define PLAYER_H
#include "cereal.h"
#include <cmath>

class Player: public Cereal{

public:
	Player(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Player();
	bool move();
	void moveR();
	void moveL();
	
private:
	int count;

};
	

#endif
