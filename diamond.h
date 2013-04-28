#ifndef DIAMOND_H
#define DIAMOND_H
#include "cereal.h"

class Diamond: public Cereal{

public:
	Diamond(double nx, double ny, int vx, int vy, QPixmap* pic, int dir);
	~Diamond();
	bool move();
	
private:
	int count;
	int count2;
	int dir_;

};
	

#endif
