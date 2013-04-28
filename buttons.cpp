#include "buttons.h"
#include "mainwindow.h"

Buttons::Buttons(MainWindow* m){
	main=m;
	
	layout = new QVBoxLayout;
	setLayout(layout);
	
	name= new QLineEdit("Enter Name");
	layout->addWidget(name);

	
	start=new QPushButton("Start Game");
	pause=new QPushButton("Pause Game");
	quit=new QPushButton("Quit Game");
	layout->addWidget(start);
	layout->addWidget(pause);
	layout->addWidget(quit);
	
	connect(start, SIGNAL(clicked()),this, SLOT(startGame()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseGame()));
	connect(quit, SIGNAL(clicked()), this, SLOT(quitGame()));
	
	rules = new QListWidget;
	QString a("RULES:");
	rules->addItem(a);
	QString rules_;
	QString b("X to move left");
	rules->addItem(b);
	QString c("C to move right");
	rules->addItem(c);
	QString d("ENTER to shoot");
	rules->addItem(d);
	QString h("Crystal Count on Left");
	rules->addItem(h);
	QString i("Score on Right");
	rules->addItem(i);
	
	layout->addWidget(rules);
	
	points= new QListWidget;
	QString points_("BALLOON--5pts");
	//points_.setText("BALLOON--5pts");
	points->addItem(points_);
	QString e("CLOVER--8pts");
	points->addItem(e);
	QString f("MOON--15pts");
	points->addItem(f);
	QString g("DIAMOND--20pts");
	points->addItem(g);
	
	layout->addWidget(points);
	
}
	
void Buttons::startGame(){
	main->startGame();
}

void Buttons::pauseGame(){
	main->pauseGame();
}

void Buttons::quitGame(){
	main->close();
}
