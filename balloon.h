#ifndef BALLOON_H
#define BALLOON_H
#include "cereal.h"

class Balloon: public Cereal{

public:
	Balloon(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Balloon();
	void move();
	
private:
	int count;

};
	

#endif
