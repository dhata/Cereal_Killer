#ifndef CLOVER_H
#define CLOVER_H
#include "cereal.h"

class Clover: public Cereal{

public:
	Clover(double nx, double ny, int vx, int vy, QPixmap* pic);
	~Clover();
	bool move();
	
private:
	int count;
	int count2;

};
	

#endif
