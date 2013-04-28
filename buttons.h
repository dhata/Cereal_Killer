#ifndef BUTTONS_H
#define BUTTONS_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QListView>
#include <QString>
#include <QListWidget>

class MainWindow;

class Buttons: public QWidget {
	Q_OBJECT
public:
	Buttons( MainWindow* m);
	
public slots:
	void startGame();
	void pauseGame();
	void quitGame();

private:

	MainWindow* main;
	QVBoxLayout* layout;
	QListWidget* rules;
	QListWidget* points;
	
public:
	QLineEdit *name;
	/** start is a button that makes the game start. */
	QPushButton *start;
	/** quit is a button that quits the program */
	QPushButton *quit;
	/** end is a button that pauses the game screen */
	QPushButton *pause;
	
	
};

#endif
