#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class GraphicsView: public QGraphicsView {
	
public:
	/** default deconstructor. creates the Graphics Scene and sets the size of both of them */
	GraphicsView();
	/** deletes the scene */
	~GraphicsView();

public:
	/** graphics scene that displays the objects in the game area */
	QGraphicsScene* boardScene;
};

#endif
