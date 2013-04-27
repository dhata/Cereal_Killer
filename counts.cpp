#include "counts.h"
#include "mainwindow.h"

Counts::Counts(MainWindow * m){

	main = m;
	
	layout= new QHBoxLayout();
	setLayout(layout);
	bubbles= new QTextEdit("Bubble Count");
	bubbles->setReadOnly(true);
	layout->addSpacing (10);
	layout->addWidget(bubbles);
	layout->addSpacing(230);
	
	score=new QTextEdit("Score Side");
	score->setReadOnly(true);
	layout->addWidget(score);
	layout->addSpacing(305);
	//show();
	
	//score->setBaseSize(100,100);
}
