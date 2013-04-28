#ifndef MOON_H
#define MOON_H
#include "cereal.h"

class Moon: public Cereal{

public:
	Moon(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Moon();
	bool move();
	
private:
	int count;

};
	

#endif
