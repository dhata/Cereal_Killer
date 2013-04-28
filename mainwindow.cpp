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
	

	//boardScene=new QGraphicsScene;
	//boardScene->setSceneRect(0, 0, 500, 475);
	
	//boardView=new QGraphicsView(boardScene);
	//boardView->setFixedSize(WINDOW_MAX_X+200, WINDOW_MAX_Y*2-120);
	
	//boardView->setAlignment(Qt::AlignLeft| Qt::AlignTop);
	
	boardView= new GraphicsView();
	setCentralWidget(boardView);
	
	
	gameStarted=false;
	
	timer=new QTimer();
	timer->setInterval(5);
	connect(timer, SIGNAL(timeout()),this, SLOT(handleTimer()));
	
	//setLayout(whole);
	frequency = 800;
	count=0;
	lives=50;
	
	balloonpic=new QPixmap("images/balloon.gif");
	starpic=new QPixmap("images/star.gif");
	playerpic=new QPixmap("images/gradient2.png");
	bulletpic=new QPixmap("images/purple.png");
	cloverpic=new QPixmap("images/clover.gif");
	diamondpic=new QPixmap("images/diamond.gif");
	moonpic=new QPixmap("images/moon.gif");
	
	setFocus();
	
}
	
MainWindow::~MainWindow() {
	
}



//void MainWindow::show(){
//	this->QMainWindow::show();
//}	

void MainWindow::mainMove(){
	list<Cereal*>::iterator it;
	for(it = objectList.begin(); it!=objectList.end();++it){
		if( !(*it)->move() ) {
			cout<< (*it)->getX() << ", " <<(*it)->getY();
			cout<< " reached the edge."<<endl;
			Cereal* temp=*it;
			boardView->boardScene->removeItem(temp);
			objectList.remove(temp);
			--it;
		}
	}
}

void MainWindow::addMonster(){
	int type= rand()%5;
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
		case 2: 
			temp=new Clover(x, y, vx, vy, cloverpic);
			break;
		case 3: 
			temp=new Diamond(x,y, vx, vy, diamondpic, dir);
			break;
		case 4: 
			temp=new Moon(x, y, vx, vy, moonpic);
			break;
		default:
			temp=new Balloon(x, y, vx, vy, balloonpic);
			break;
	}
	//temp=new Diamond(x,y, vx, vy, diamondpic, dir);
	//temp=new Balloon(100, 0, vx, vy, balloonpic);
	cout<<x<< ", " <<y<< "  " << vx<<", " <<vy<<endl;
	objectList.push_back(temp);
	boardView->boardScene->addItem(temp);
}

void MainWindow::endScore(){
	timer->stop();
	counts_->bubbles->setText("GAME OVER.");

	counts_->bubbles->append("FINAL SCORE: " + counts_->score->toPlainText());
	buttons_->pause->setDisabled(true);
	buttons_->start->setDisabled(true);
}

void MainWindow::keyPressEvent( QKeyEvent *e){
	if(gameStarted&&timer->isActive()){
	if( e->key()== Qt::Key_C){
		player_->moveR();
	} else if (e->key()==Qt::Key_X){
		player_->moveL();
	} else if( e->key()==Qt::Key_Enter){
		//make a new bullet/add to the objectList
	} else {
		if(lives>0){
		Cereal* temp= new Bullet(player_->getX()+7, player_->getY(), 0, -10, bulletpic);
		objectList.push_back(temp);
		boardView->boardScene->addItem(temp);
		lives--;
		QString a;
		a.setNum(lives);
		counts_->bubbles->setText(a);
		}
		else {
			endScore();
		}
	}
	}
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
	QString a;
	a.setNum(lives);
	counts_->bubbles->setText(a);
	player_=new Player(X_COORD/2-35, Y_COORD-57,5,5, playerpic);
	boardView->boardScene->addItem(player_);
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
	if(count==frequency){
		frequency--;
		addMonster();
		count=0;
	}
	count++;
}

	
	

