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
	/** main constructor. accepts a pointer to the MainWindow that the Buttons object will be in. initializes the buttons, instructions, point values, and username QLineEdit */ 
	Buttons( MainWindow* m);
	
public slots:
	/** calls startGame in the MainWindow */
	void startGame();
	/** calls pauseGame in the MainWindow */
	void pauseGame();
	/** closes the MainWindow/ending the program */
	void quitGame();

private:
	/** pointer to the containing MainWindow */
	MainWindow* main;
	/** a vBoxlayout to organize the Widget */
	QVBoxLayout* layout;
	/** a QListWidget that lists the game controls */
	QListWidget* rules;
	/** lists the point values of the objects */
	QListWidget* points;
	
	
public:
	/** name is a QLineEdit that accepts the player's username */
	QLineEdit *name;
	/** start is a button that makes the game start. */
	QPushButton *start;
	/** quit is a button that quits the program */
	QPushButton *quit;
	/** end is a button that pauses the game screen */
	QPushButton *pause;
	/** lists the high scores */
	QListWidget* highS;
	
};

#endif
