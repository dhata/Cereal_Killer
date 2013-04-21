#include "mainwindow.h"
#include <iostream>


MainWindow::MainWindow() {

	setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
	setWindowTitle( "Cereal Killer -- dhata");	
	
	whole= new QGridLayout();
	
	name= new QLineEdit("Enter Name");
	whole->addWidget(name,0,5);

	
	start=new QPushButton("Start Game");
	pause=new QPushButton("Pause Game");
	quit=new QPushButton("Quit Game");
	whole->addWidget(start,1,5);
	whole->addWidget(pause,2,5);
	whole->addWidget(quit,3,5);
	
	connect(start, SIGNAL(clicked()),this, SLOT(startGame()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
	connect(quit, SIGNAL(clicked()), this, SLOT(close()));
	
	boardScene=new QGraphicsScene;
	//boardScene->setSceneRect(0,0,WINDOW_MAX_X+200, WINDOW_MAX_Y*2-125);
	boardView=new QGraphicsView(boardScene);
	boardView->setFixedSize(WINDOW_MAX_X+200, WINDOW_MAX_Y*2-125);
	boardView->setAlignment(Qt::AlignLeft| Qt::AlignTop);
	whole->addWidget(boardView,0,0,5,5);
	
	score=new QTextEdit;
	score->setReadOnly(true);
	
	score->setBaseSize(100,100);
	
	whole->addWidget(score, 6,3);
	whole->setSpacing(20);
	
	for(int i=0; i<6;i++){
		whole->setColumnMinimumWidth(i,100);
	}
	gameStarted=false;
	
	timer=new QTimer();
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()),this, SLOT(handleTimer()));
	
	setLayout(whole);
	frequency = 20;
	count=0;
	
	balloonpic=new QPixmap("images/balloon.gif");
}
	
MainWindow::~MainWindow() {
	
}



void MainWindow::show(){
	this->QGraphicsView::show();
}	

void MainWindow::mainMove(){
	list<Cereal*>::iterator it;
	for(it = objectList.begin(); it!=objectList.end();++it){
		int nx= (*it)->getX();
		int ny= (*it)->getY();
		int vx= (*it)->getVelocityX();
		int vy= (*it)->getVelocityY();
		nx+= vx;
		ny+= vy;
		if( nx<0 || ny<0 || nx> (WINDOW_MAX_X) || ny> (WINDOW_MAX_Y)){
			cout<< " reached the edge."<<endl;
			Cereal* temp=*it;
			boardScene->removeItem(temp);
			objectList.remove(temp);
			--it;
		} else{
			 (*it)->move();
		}
	}
}

void MainWindow::addMonster(){
	//int type= rand()%4;
	int dir= rand()%3;
	int x, y;
	if(dir==0){	//enter from the left
		x=0;
		y= rand()%(WINDOW_MAX_Y);
	} else if(dir==1){	//enter from the top
		x= rand()%(WINDOW_MAX_X);
		y=0;
	} else {	//enter from the right
		x=WINDOW_MAX_X;
		y= rand()%(WINDOW_MAX_Y);
	}
	int vx = rand()%20-10;
	int vy = rand()%20-10;
	if(vx==0){
		vx++;
	}
	if(vy==0){
		vy++;
	}
	Cereal* temp;
	temp=new Balloon(x, y, vx, vy, balloonpic);
	cout<<x<< ", " <<y<<endl;
	objectList.push_back(temp);
	boardScene->addItem(temp);
}
			

void MainWindow::startGame(){
	if(gameStarted){
		return;
	}
	gameStarted=true;
	user=name->text();
	name->setDisabled(true);
	timer->start();
	score->setText("0");
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
	mainMove();
	if(count==50*frequency){
		frequency--;
		addMonster();
		count=0;
	}
	count++;
}

	
	

