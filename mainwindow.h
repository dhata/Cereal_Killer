#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QLineEdit>
#include <QRadioButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QListWidget>
#include <QPixmap>
#include <QDockWidget>
#include "buttons.h"
#include <list>
#include "cereal.h"
#include "balloon.h"
#include "star.h"
#include "counts.h"

using namespace std;

#define WINDOW_MAX_X 500
#define X_COORD 700
#define WINDOW_MAX_Y 300
#define Y_COORD 475

/** MainWindow Class
 */
class MainWindow : public QMainWindow{
	Q_OBJECT
public: 
	/** default constructor 
	 * initializes the items to be put into the view, also initializes the layouts and nests them for proper display.
	 * sets the initial gameStarted attribute to false. */
	explicit MainWindow();
	/** default deconstructor
	 * deletes some of the QT objects that were declared on the heap */
	~MainWindow();
	
	/** show function displays the MainWindow and all of the objects inside */
	void show();
	
	void mainMove();
	
	void addMonster();
	

public slots:
	void startGame();
	
	void pauseGame();
	
	void handleTimer();
	
	//void close();

	//void readData();
private:
	
	
	/** Scene holds the QT items */
	//QGraphicsScene *scene;
	/** timer lets the objects move continuously */
	QTimer *timer;
	//QLineEdit *name;
	/** start is a button that makes the game start. */
	//QPushButton *start;
	/** quit is a button that quits the program */
	//QPushButton *quit;
	/** end is a button that pauses the game screen */
	//QPushButton *pause;
	
	/** boardScene is where the game is displayed */
	QGraphicsScene *boardScene;
	/** boardView displays the boardScene in the layout and defines the area it can take up */
	QGraphicsView *boardView;
	
	
	/** vboxlayout that governs the whole window */
	QGridLayout *whole;
	
	QTextEdit *score;
	
	/** gameStarted attribute is true when there is a board in the window. */
	bool gameStarted;
	
	QString user;
	int frequency;
	int count;
	int count2;
	
	list<Cereal*> objectList;
	QPixmap * balloonpic;
	QPixmap * starpic;
	QDockWidget* commands;
	Buttons* buttons_;
	
	QDockWidget* numbers;
	Counts* counts_;
	
	
	
};	

#endif
