#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class GraphicsView: public QGraphicsView {
	
public:
	GraphicsView();
	~GraphicsView();

public:
	QGraphicsScene* boardScene;
	//Player* player_;
};

#endif
