#include "graphicsview.h"

GraphicsView::GraphicsView() {
	boardScene=new QGraphicsScene();
	setScene(boardScene);
	boardScene->setSceneRect(0,0, 500, 475);
	setFixedSize(500+185, 300*2-120);
	setAlignment(Qt::AlignLeft | Qt::AlignTop);
	boardScene->setBackgroundBrush(QBrush(QImage("images/large-white2-tile.png")));
	//setPixmap(new QPixmap("images/large-white2-tile.png"));
}

GraphicsView::~GraphicsView(){
	delete boardScene;
}
