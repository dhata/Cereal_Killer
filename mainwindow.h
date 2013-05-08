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
#include <QKeyEvent>
#include <QString>
#include <QPainter>
#include <string>
#include <queue>
#include <fstream>
#include <string>
#include "buttons.h"
#include <list>
#include "cereal.h"
#include "balloon.h"
#include "star.h"
#include "counts.h"
#include "graphicsview.h"
#include "player.h"
#include "bullet.h"
#include "clover.h"
#include "diamond.h"
#include "moon.h"
#include "highscore.h"
#include "hsmaxlist.h"


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
	 * initializes the Qt Items to be put into the mainwindow, also initializes the qdockWidgets and sets them for proper display.
	 * sets the initial gameStarted attribute to false. */
	explicit MainWindow();
	/** default deconstructor
	 * deletes some of the QT objects that were declared on the heap */
	~MainWindow();
	
	/** mainMove function calls move on all of the objects in the play area. if the item moves out of the play area, then it is removed from the view and the objectList.
	 * handles collision. if any object collides with a star(except another star) then it is removed. if a not star object collides with a bullet, then both are removed from the game and lives/points are awarded. */
	void mainMove();
	
	/** addMonster function generates a direction from which to insert a new monster, generates random locations(near the edges), random velocities, and randomly creates one of 5 monsters. */
	void addMonster();
	
	/** endScore function is called when lives reaches zero. stops the game, makes the pause button invalid, displays the final score and player's name. disables any continued gameplay until game is reset. */
	void endScore();
	
	/** adds lives/points based on what item was deleted/destroyed. is called when a bullet collides with an object */
	void calc(char type);
	
	/** updates the HighScore table in the buttons docking widget */
	void displayHS();
	
	/** reads in the high scores from a file */
	void readScores();
	
	/** prints the high scores to a file */
	void printScores();
	
protected: 
	/** captures key presses, only completes actions when x, c or m are passed to the game
	 * only accepts keys if the timer is runnng. */
	void keyPressEvent (QKeyEvent *e);
	

public slots:
	/** if the game has not been started yet,it initializes the player and places it in the game area. sets the score/crystal numbers to the inital values.
	 * if the game has been started, it resets all scores/lives to the initial values, removes items and the player from the play area. */
	void startGame();
	
	/** stops the timer if it is running, starts the timer if it is not running. */
	void pauseGame();
	
	/** calls mainMove, at a set interval, adds more monsters to the game, the interval gets smaller each time a monster is created */
	void handleTimer();
	
private:
	
	/** timer lets the objects move continuously */
	QTimer *timer;
	
	/** boardView is where the player/monsters are displayed and move */
	GraphicsView *boardView;
	
	/** gameStarted attribute is true when there is a board in the window. */
	bool gameStarted;
	
	/** a string for storing the player's name read in */
	QString user;
	
	/** frequency at which the monsters are added to the game */
	int frequency;
	
	/** count for frequency. increased each time the timer ticks */
	int count;
	
	/** list for holding all the monsters/bullets in play */
	list<Cereal*> objectList;
	
	/** pointer to the balloon icon */
	QPixmap * balloonpic;
	/** pointer to the star icon */
	QPixmap * starpic;
	/** pointer to the player's icon */
	QPixmap * playerpic;
	/** pointer to the bullet icon */
	QPixmap * bulletpic;
	/** pointer to the clover icon */
	QPixmap * cloverpic;
	/** pointer to the diamond icon */
	QPixmap * diamondpic;
	/** pointer to the moon icon */
	QPixmap * moonpic;
	
	/** dockWidget where the buttons, instructions, and points key are stored */
	QDockWidget* commands;
	/** Widget that contains the buttons, instructions, and points keys, to be added to the commands_ dockWidget */
	Buttons* buttons_;
	
	/** dockWidget where the score/crystals counts are stored. */
	QDockWidget* numbers;
	/** Widget that contains the score/crystal count to be added to the numbers dockWidget */
	Counts* counts_;
	
	/** pointer to the player. uninitialized at first. gets initialized in the startGame function */
	Player* player_;
	/** current number of crystals that the player has. starts at 50 */
	int lives;
	/** running total of the player's points. */
	int points_;
	
	/** an int that indicates the level of the game */
	int level;
	
	/** a list sorted in descending order of HighScore pointers */
	HSMaxList scoreTable;
	
	
	
};	

#endif
