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
