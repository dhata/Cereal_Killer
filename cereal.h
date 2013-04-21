#ifndef CEREAL_H
#define CEREAL_H
#include <QGraphicsPixmapItem>

/**
  This class maintains the location, size, and speed of a QGraphicsPixmapItem.
  */
class Cereal : public QGraphicsPixmapItem {
public:
    Cereal(double nx, double ny, int vx, int vy, QPixmap* pic );
    void setX( int x );
    void setY( int y );
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    virtual void move()=0;

protected:
    int x;
    int y;
    int velocityX;
    int velocityY;
    QPixmap* picture;
};

#endif // BOUNCINGRECTANGLE_H
