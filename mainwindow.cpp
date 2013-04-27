#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow() {

	setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
	setWindowTitle( "Cereal Killer -- dhata");
		
	commands = new QDockWidget();
	buttons_=new Buttons(this);
	commands->setWidget(buttons_);
	addDockWidget(Qt::RightDockWidgetArea, commands);
	commands->setFeatures(QDockWidget::NoDockWidgetFeatures);
	
	numbers = new QDockWidget();
	counts_=new Counts(this);
	numbers->setWidget(counts_);
	addDockWidget(Qt::BottomDockWidgetArea, numbers);
	numbers->setFeatures(QDockWidget::NoDockWidgetFeatures);
	

	boardScene=new QGraphicsScene;
	boardScene->setSceneRect(0, 0, 500, 475);
	
	boardView=new QGraphicsView(boardScene);
	boardView->setFixedSize(WINDOW_MAX_X+200, WINDOW_MAX_Y*2-120);
	
	boardView->setAlignment(Qt::AlignLeft| Qt::AlignTop);
	
	setCentralWidget(boardView);
	
	gameStarted=false;
	
	timer=new QTimer();
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()),this, SLOT(handleTimer()));
	
	//setLayout(whole);
	frequency = 20;
	count=0;
	count2=0;
	
	balloonpic=new QPixmap("images/balloon.gif");
	starpic=new QPixmap("images/star.gif");
}
	
MainWindow::~MainWindow() {
	
}



void MainWindow::show(){
	this->QMainWindow::show();
}	

void MainWindow::mainMove(){
	list<Cereal*>::iterator it;
	for(it = objectList.begin(); it!=objectList.end();++it){
		if( !(*it)->move() ) {
			cout<< nx << ", " <<ny;
			cout<< " reached the edge."<<endl;
			Cereal* temp=*it;
			boardScene->removeItem(temp);
			objectList.remove(temp);
			--it;
		}
	}
}

void MainWindow::addMonster(){
	int type= rand()%2;
	int dir= rand()%3;
	int x, y;
	int vx, vy;
	vx = rand()%10+1;
	vy = rand()%10+1;
	int p=rand()%2;
	if(dir==0){	//enter from the left
		x=0;	//stay positive
		y= rand()%(Y_COORD-60);
		if( p ){
			vy*=-1;	//times plus or minus
		}
	} else if(dir==1){	//enter from the top
		x= rand()%(X_COORD-60);
		if( p ){
			vx*=-1;	//times + or -
		}
		y=0;	//stay positive
	} else {	//enter from the right
		x=X_COORD-60;
		vx*=-1;
		y= rand()%(Y_COORD-60);
		if( p ){
			vy*=-1;	//times +or-
		}
	}
	
	Cereal* temp;
	switch(type){
		case 0:
			temp=new Balloon(x, y, vx, vy, balloonpic);
			break;
		case 1:
			temp=new Star(x, y, vx, vy, starpic);
			break;
	}
	//temp=new Balloon(100, 0, vx, vy, balloonpic);
	cout<<x<< ", " <<y<< "  " << vx<<", " <<vy<<endl;
	objectList.push_back(temp);
	boardScene->addItem(temp);
}
			

void MainWindow::startGame(){
	if(gameStarted){
		return;
	}
	gameStarted=true;
	user=buttons_->name->text();
	buttons_->name->setDisabled(true);
	timer->start();
	counts_->score->setText("0");
}

void MainWindow::pauseGame(){
	if(gameStarted){
		if(timer->isActive()){
			timer->stop();
		} else {
			timer->start();
		}
	} else return;
}
	
void MainWindow::handleTimer(){
	//if(count2==20){
		mainMove();
	//}
	if(count==50*frequency){
		frequency--;
		addMonster();
		count=0;
	}
	count++;
}

	
	

