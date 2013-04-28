#ifndef BULLET_H
#define BULLET_H
#include "cereal.h"
#include <cmath>

class Bullet: public Cereal{

public:
	Bullet(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Bullet();
	bool move();
	
private:
	int count;

};
	

#endif
