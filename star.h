#ifndef STAR_H
#define STAR_H
#include "cereal.h"
#include <cmath>

class Star: public Cereal{

public:
	Star(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Star();
	bool move();
	
private:
	int count;

};
	

#endif
