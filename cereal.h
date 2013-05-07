#ifndef CEREAL_H
#define CEREAL_H
#include <QGraphicsPixmapItem>

/**
  This class maintains the location, size, and speed of a QGraphicsPixmapItem.
  */
class Cereal : public QGraphicsPixmapItem {
public:
    /** default constructor. sets the Cereal's initial positon, velocities, sets the QPixmap*/
    Cereal(double nx, double ny, int vx, int vy, QPixmap* pic, int level );
    /** sets the x value */
    void setX( int x );
    /** sets the y value */
    void setY( int y );
    /** returns the x position */
    int getX();
    /** returns the y position */
    int getY();
    /** returns the x velocity */
    int getVelocityX();
    /** returns the y velocity */
    int getVelocityY();
    /** returns the cereal type in the form of a char */
    char getType();
    /** decreases the level/durability of the Cereal. if the level becomes 0, then returns true */
    bool decrease();
    /** virtual function move that must be implemented differently for every object that inherits Cereal */
    virtual bool move()=0;

protected:
    /** the x position of the object */
    int x;
    /** the y position of the object */
    int y;
    /** the x velocity of the object */
    int velocityX;
    /** the y velocity of the object */
    int velocityY;
    /** pointer to the QPixmap that the object displays */
    QPixmap* picture;
    /** char representation of the Cereal type */
    char type;
    /** number of lives that an object has */
    int level_;
};

#endif // BOUNCINGRECTANGLE_H
