#ifndef COUNTS_H
#define COUNTS_H
#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>

class MainWindow;

class Counts: public QWidget {
	Q_OBJECT
public:
	Counts( MainWindow* m);
	

private:

	MainWindow* main;
	QHBoxLayout* layout;
	
public:
	QTextEdit *bubbles;
	QTextEdit *score;
};

#endif
