#include "cereal.h"

Cereal::Cereal(double nx, double ny, int vx, int vy, QPixmap* pic ) :
    QGraphicsPixmapItem(*pic) {
    x = nx;
    y = ny;
    velocityX = vx;
    velocityY = vy;
    setPos(x, y);
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

