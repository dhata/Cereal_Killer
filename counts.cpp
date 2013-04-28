#include "counts.h"
#include "mainwindow.h"

Counts::Counts(MainWindow * m){

	main = m;
	
	layout= new QHBoxLayout();
	setLayout(layout);
	crystals= new QTextEdit("Crystal Count");
	crystals->setReadOnly(true);
	layout->addSpacing (10);
	layout->addWidget(crystals);
	layout->addSpacing(230);
	
	score=new QTextEdit("Score Side");
	score->setReadOnly(true);
	layout->addWidget(score);
	layout->addSpacing(305);
	//show();
	
	//score->setBaseSize(100,100);
}
