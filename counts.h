#ifndef COUNTS_H
#define COUNTS_H
#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>

class MainWindow;

class Counts: public QWidget {
	Q_OBJECT
public:
	/** main constructor. initializes the QTextEdits that display the crystal count and score */
	Counts( MainWindow* m);
	

private:
	/** a pointer to the containing mainwindow */
	MainWindow* main;
	/** a HBoxLayout that organizes the Widget */
	QHBoxLayout* layout;
	
public:
	/** crystals displays the crystal count. goes down with every crystal shot. increases with each kill */
	QTextEdit *crystals;
	/** score displays the score in the game. increases with every kill, but does not decrease. */
	QTextEdit *score;
};

#endif
