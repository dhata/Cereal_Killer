#include "cereal.h"

Cereal::Cereal(double nx, double ny, int vx, int vy, QPixmap* pic, int level ) :
    QGraphicsPixmapItem(*pic) {
    x = nx;
    y = ny;
    velocityX = vx;
    velocityY = vy;
    setPos(x, y);
   // move(x,y);
   level_=level;
}

int Cereal::getX() {
    return x;
}

int Cereal::getY() {
    return y;
}

int Cereal::getVelocityX() {
    return velocityX;
}

int Cereal::getVelocityY() {
    return velocityY;
}

void Cereal::setX(int nx) {
    x = nx;
}

void Cereal::setY(int ny) {
    y = ny;
}

char Cereal::getType() {
    return type;
}

bool Cereal::decrease(){
    level_--;
    if( level_==0 ){
    	return true;
    } else {
    	return false;
    }
}

